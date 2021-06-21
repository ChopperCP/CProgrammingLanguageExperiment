//
// Created by win10 on 2021/6/20.
//

#include "import_export.h"


// Test function
// NOTE: Returns a heap allocated string, you are required to free it after use.
char *create_monitor_with_helpers(void) {
    const unsigned int resolution_numbers[3][2] = {
            {1280, 720},
            {1920, 1080},
            {3840, 2160}
    };
    char *string = NULL;
    cJSON *resolutions = NULL;
    size_t index = 0;

    cJSON *monitor = cJSON_CreateObject();

    if (cJSON_AddStringToObject(monitor, "name", "Awesome 4K") == NULL) {
        goto end;
    }

    resolutions = cJSON_AddArrayToObject(monitor, "resolutions");
    if (resolutions == NULL) {
        goto end;
    }

    for (index = 0; index < (sizeof(resolution_numbers) / (2 * sizeof(int))); ++index) {
        cJSON *resolution = cJSON_CreateObject();

        if (cJSON_AddNumberToObject(resolution, "width", resolution_numbers[index][0]) == NULL) {
            goto end;
        }

        if (cJSON_AddNumberToObject(resolution, "height", resolution_numbers[index][1]) == NULL) {
            goto end;
        }

        cJSON_AddItemToArray(resolutions, resolution);
    }

    string = cJSON_Print(monitor);
    if (string == NULL) {
        fprintf(stderr, "Failed to print monitor.\n");
    }

    end:
    cJSON_Delete(monitor);
    return string;
}
// Test function
/* return 1 if the monitor supports full hd, 0 otherwise */
int supports_full_hd(const char *const monitor) {
    const cJSON *resolution = NULL;
    const cJSON *resolutions = NULL;
    const cJSON *name = NULL;
    int status = 0;
    cJSON *monitor_json = cJSON_Parse(monitor);
    if (monitor_json == NULL) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error before: %s\n", error_ptr);
        }
        status = 0;
        goto end;
    }

    name = cJSON_GetObjectItemCaseSensitive(monitor_json, "name");
    if (cJSON_IsString(name) && (name->valuestring != NULL)) {
        printf("Checking monitor \"%s\"\n", name->valuestring);
    }

    resolutions = cJSON_GetObjectItemCaseSensitive(monitor_json, "resolutions");
    cJSON_ArrayForEach(resolution, resolutions) {
        cJSON *width = cJSON_GetObjectItemCaseSensitive(resolution, "width");
        cJSON *height = cJSON_GetObjectItemCaseSensitive(resolution, "height");

        if (!cJSON_IsNumber(width) || !cJSON_IsNumber(height)) {
            status = 0;
            goto end;
        }

        if ((width->valuedouble == 1920) && (height->valuedouble == 1080)) {
            status = 1;
            goto end;
        }
    }

    end:
    cJSON_Delete(monitor_json);
    return status;
}


int export_student_table(char *path, struct StudentTable *student_table) {
    cJSON *table = cJSON_CreateObject();

    cJSON_AddStringToObject(table, "type", student_table->type);
    cJSON_AddNumberToObject(table, "last_available", student_table->last_available);
    cJSON *data = cJSON_AddArrayToObject(table, "data");

    for (int i = 0; i < student_table->last_available; ++i) {
        struct Student *student = student_table->data[i];
        cJSON *entry = cJSON_CreateObject();
        cJSON_AddNumberToObject(entry, "student_number", student->student_number);
        cJSON_AddStringToObject(entry, "student_name", student->student_name);
        cJSON_AddStringToObject(entry, "gender", student->gender);
        cJSON_AddNumberToObject(entry, "age", student->age);
        cJSON_AddStringToObject(entry, "school", student->school);

        cJSON_AddItemToArray(data, entry);
    }

    FILE *fd = fopen(path, "w");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    fputs(cJSON_Print(table), fd);
    cJSON_Delete(table);
    fclose(fd);
    printf("[*] Exported StudentTable to %s.\n", path);

    return 0;
}

int import_student_table(char *path, struct StudentTable *student_table) {
    FILE *fd = fopen(path, "r");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    char* buffer=malloc(sizeof(char)*MAX_FILE_BUFFER_SIZE);
    fread(buffer, MAX_FILE_BUFFER_SIZE, 1, fd);

    cJSON *table_json = cJSON_Parse(buffer);
    strcpy(student_table->type, cJSON_GetObjectItemCaseSensitive(table_json, "type")->valuestring);
    // last_available will be determined by the real entry count
//    student_table->last_available = cJSON_GetObjectItemCaseSensitive(table_json, "last_available")->valueint;
    cJSON *table_json_data = cJSON_GetObjectItemCaseSensitive(table_json, "data");

    cJSON *student_json = NULL;
    int i = 0;
    cJSON_ArrayForEach(student_json, table_json_data) {
        struct Student *student = malloc(sizeof(struct Student));
        student->student_number = cJSON_GetObjectItemCaseSensitive(student_json, "student_number")->valueint;
        strcpy(student->student_name, cJSON_GetObjectItemCaseSensitive(student_json, "student_name")->valuestring);
        strcpy(student->gender, cJSON_GetObjectItemCaseSensitive(student_json, "gender")->valuestring);
        student->age = cJSON_GetObjectItemCaseSensitive(student_json, "age")->valueint;
        strcpy(student->school, cJSON_GetObjectItemCaseSensitive(student_json, "school")->valuestring);

        student_table->data[i] = student;
        student_table->last_available = i;
        ++i;
    }

    printf("[*] Imported StudentTable from %s.\n", path);
    free(buffer);
    return 0;
}



int export_course_table(char *path, struct CourseTable *course_table) {
    cJSON *table = cJSON_CreateObject();

    cJSON_AddStringToObject(table, "type", course_table->type);
    cJSON_AddNumberToObject(table, "last_available", course_table->last_available);
    cJSON *data = cJSON_AddArrayToObject(table, "data");

    for (int i = 0; i < course_table->last_available; ++i) {
        struct Course *course = course_table->data[i];
        cJSON *entry = cJSON_CreateObject();
        cJSON_AddNumberToObject(entry, "course_number", course->course_number);
        cJSON_AddStringToObject(entry, "course_name", course->course_name);
        cJSON_AddNumberToObject(entry, "required_course_number", course->required_course_number);
        cJSON_AddNumberToObject(entry, "credit", course->credit);

        cJSON_AddItemToArray(data, entry);
    }

    FILE *fd = fopen(path, "w");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    fputs(cJSON_Print(table), fd);
    cJSON_Delete(table);
    fclose(fd);
    printf("[*] Exported CourseTable to %s.\n", path);

    return 0;
}

int import_course_table(char *path, struct CourseTable *course_table) {
    FILE *fd = fopen(path, "r");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    char* buffer=malloc(sizeof(char)*MAX_FILE_BUFFER_SIZE);
    fread(buffer, MAX_FILE_BUFFER_SIZE, 1, fd);

    cJSON *table_json = cJSON_Parse(buffer);
    strcpy(course_table->type, cJSON_GetObjectItemCaseSensitive(table_json, "type")->valuestring);
    // last_available will be determined by the real entry count
//    course_table->last_available = cJSON_GetObjectItemCaseSensitive(table_json, "last_available")->valueint;
    cJSON *table_json_data = cJSON_GetObjectItemCaseSensitive(table_json, "data");

    cJSON *course_json = NULL;
    int i = 0;
    cJSON_ArrayForEach(course_json, table_json_data) {
        struct Course *course = malloc(sizeof(struct Course));
        course->course_number = cJSON_GetObjectItemCaseSensitive(course_json, "course_number")->valueint;
        strcpy(course->course_name, cJSON_GetObjectItemCaseSensitive(course_json, "course_name")->valuestring);
        course->required_course_number = cJSON_GetObjectItemCaseSensitive(course_json, "required_course_number")->valueint;
        course->credit = cJSON_GetObjectItemCaseSensitive(course_json, "credit")->valuedouble;

        course_table->data[i] = course;
        course_table->last_available = i;
        ++i;
    }

    printf("[*] Imported CourseTable from %s.\n", path);
    free(buffer);
    return 0;
}


int export_student_course_table(char *path, struct StudentCourseTable *student_course_table) {
    cJSON *table = cJSON_CreateObject();

    cJSON_AddStringToObject(table, "type", student_course_table->type);
    cJSON_AddNumberToObject(table, "last_available", student_course_table->last_available);
    cJSON *data = cJSON_AddArrayToObject(table, "data");

    for (int i = 0; i < student_course_table->last_available; ++i) {
        struct StudentCourse *student_course = student_course_table->data[i];
        cJSON *entry = cJSON_CreateObject();
        cJSON_AddNumberToObject(entry, "student_number", student_course->student_number);
        cJSON_AddNumberToObject(entry, "course_number", student_course->course_number);
        cJSON_AddNumberToObject(entry, "grade", student_course->grade);

        cJSON_AddItemToArray(data, entry);
    }

    FILE *fd = fopen(path, "w");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    fputs(cJSON_Print(table), fd);
    cJSON_Delete(table);
    fclose(fd);
    printf("[*] Exported StudentCourseTable to %s.\n", path);

    return 0;
}

int import_student_course_table(char *path, struct StudentCourseTable *student_course_table) {
    FILE *fd = fopen(path, "r");
    if (fd == NULL) {
        printf("[!] fopen() error!\n");
        return -1;
    }
    char* buffer=malloc(sizeof(char)*MAX_FILE_BUFFER_SIZE);
    fread(buffer, MAX_FILE_BUFFER_SIZE, 1, fd);

    cJSON *table_json = cJSON_Parse(buffer);
    strcpy(student_course_table->type, cJSON_GetObjectItemCaseSensitive(table_json, "type")->valuestring);
    // last_available will be determined by the real entry count
//    student_course_table->last_available = cJSON_GetObjectItemCaseSensitive(table_json, "last_available")->valueint;
    cJSON *table_json_data = cJSON_GetObjectItemCaseSensitive(table_json, "data");

    cJSON *student_course_json = NULL;
    int i = 0;
    cJSON_ArrayForEach(student_course_json, table_json_data) {
        struct StudentCourse *student_course = malloc(sizeof(struct StudentCourse));
        student_course->student_number = cJSON_GetObjectItemCaseSensitive(student_course_json, "student_number")->valueint;
        student_course->course_number = cJSON_GetObjectItemCaseSensitive(student_course_json, "course_number")->valueint;
        student_course->grade = cJSON_GetObjectItemCaseSensitive(student_course_json, "grade")->valuedouble;

        student_course_table->data[i] = student_course;
        student_course_table->last_available = i;
        ++i;
    }

    printf("[*] Imported StudentCourseTable from %s.\n", path);
    free(buffer);
    return 0;
}



