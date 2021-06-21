//
// Created by win10 on 2021/6/19.
//

#include "Course.h"

struct CourseTable init_course_table() {
    struct CourseTable table;
    strcpy(table.type, "C");

    // Fill the table with 50 demo entries
    for (int i = 1; i <= 50; ++i) {
        // Init Course
        struct Course *demo_course = malloc(sizeof(struct Course));
        memset(demo_course, 0, sizeof(struct Course));      // Clean up the memory.

        demo_course->course_number = i;
        strcpy(demo_course->course_name, "A course about something");
        demo_course->required_course_number = 1;
        demo_course->credit = 1;

        // Fill the table
        table.data[i - 1] = demo_course;
        table.last_available = i;
    }
    return table;
}

int compare_course(const void *lhs, const void *rhs) {
    unsigned int lhs_course_number = (*((struct Course **) lhs))->course_number;
    unsigned int rhs_course_number = (*((struct Course **) rhs))->course_number;
    return lhs_course_number - rhs_course_number;
}

int add_course(struct CourseTable *table, struct Course *course) {
    if (table->last_available >= MAX_COURSE_TABLE_ENT_CNT) {
        printf("[!] Not enough space in the table.");
        return -1;
    }
    // Insert the course to the last place.
    table->data[table->last_available++] = course;
    // Sort the table.
    qsort(table->data, table->last_available, sizeof(struct Course *), compare_course);

    return 0;
}

int compare_student_course_course_number(const void *lhs, const void *rhs) {
    // Compare using course_number instead of student_number
    unsigned int lhs_course_number = (*((struct StudentCourse **) lhs))->course_number;
    unsigned int rhs_course_number = (*((struct StudentCourse **) rhs))->course_number;
    return lhs_course_number - rhs_course_number;
}

void _clean_Course_from_CourseTable(struct Course **result_course, struct CourseTable *course_table) {
    struct Course **start = result_course;
    struct Course **end = result_course;
    struct Course **last_table_entry = &(course_table->data[course_table->last_available - 1]);

    while ((*end)->course_number == (*result_course)->course_number) {
        printf("[*] Entry found, course number: %u\n", (*end)->course_number);
        ++end;
    }
    // From start-end is the memory which will be cleaned.
    // Move the rest forward.
    while (end <= last_table_entry) {
        memcpy(start++, end++, sizeof(struct Course *));
    }
    course_table->last_available -= end - start;
}

void _clean_Course_from_StudentCourseTable(struct StudentCourse **result_student_course,
                                           struct StudentCourseTable *student_course_table) {
    struct StudentCourse **start = result_student_course;
    struct StudentCourse **end = result_student_course;
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);

    while ((*end)->course_number == (*result_student_course)->course_number) {
        printf("[*] Entry found, course number: %u, student number: %u\n", (*end)->course_number,(*end)->student_number);
        ++end;
    }
    // From start-end is the memory which will be cleaned.
    // Move the rest forward.
    while (end <= last_table_entry) {
        memcpy(start++, end++, sizeof(struct StudentCourse *));
    }
    student_course_table->last_available -= end - start;
}

int remove_course(struct CourseTable *course_table, struct StudentCourseTable *student_course_table,
                  struct Course *target_course) {
    // Only course_number in target_course is searched, other elements in target_course are ignored.
    struct Course **result_course = bsearch(&target_course, course_table->data, course_table->last_available,
                                            sizeof(struct Course *), compare_course);
    if (result_course == NULL) {
        printf("[!] Course with the number %u not found!\n", target_course->course_number);
    } else {
        printf("[*] Course with the number %u found, name: %s.\n", target_course->course_number,
               (*result_course)->course_name);
    }

    // Remove course from course_table
    _clean_Course_from_CourseTable(result_course, course_table);

    // Can't use binary search in SC because there are more than 1 entry which has the same course_number.
    // Resort student_course_table using course_number.
    qsort(student_course_table->data, student_course_table->last_available, sizeof(struct StudentCourse *),
          compare_student_course_course_number);
    struct StudentCourse **result_student_course = &student_course_table->data[0];
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);
    while ((result_student_course <= last_table_entry) &&
           ((*result_student_course)->course_number != target_course->course_number)) {
        ++result_student_course;
    }
//    struct  StudentCourse** result_student_course=bsearch(&target_student,student_course_table->data,student_course_table->last_available,sizeof(struct StudentCourse*),compare_student_student_course);
    if (result_student_course > last_table_entry) {
        // Result not found
        result_student_course = NULL;
    }
    if (result_student_course == NULL) {
        printf("[*] Course with the number %u not found in SC\n", target_course->course_number);
        return -1;
    } else {
        printf("[*] Course with the number %u found in SC, student number: %u.\n", target_course->course_number,
               (*result_student_course)->student_number);
        // Remove course from student_course table.
        _clean_Course_from_StudentCourseTable(result_student_course, student_course_table);
    }
    // Sort back using student_number
    qsort(student_course_table->data, student_course_table->last_available, sizeof(struct StudentCourse *),
          compare_student_course);

    return 0;
}

int update_course_name(struct CourseTable *course_table, struct Course *target_course) {
    // Only course_number in target_course is searched, other elements in target_course are ignored.
    struct Course **result_course = bsearch(&target_course, course_table->data, course_table->last_available,
                                            sizeof(struct Course *), compare_course);
    if (result_course == NULL) {
        printf("[!] Course with the number %u not found!\n", target_course->course_number);
    } else {
        printf("[*] Course with the number %u found, name: %s.\n", target_course->course_number,
               (*result_course)->course_name);
    }

    // Operations
    strcpy((*result_course)->course_name, target_course->course_name);

    return 0;
}

int update_course_required_course_number(struct CourseTable *course_table, struct Course *target_course) {
    // Only course_number in target_course is searched, other elements in target_course are ignored.
    struct Course **result_course = bsearch(&target_course, course_table->data, course_table->last_available,
                                            sizeof(struct Course *), compare_course);
    if (result_course == NULL) {
        printf("[!] Course with the number %u not found!\n", target_course->course_number);
    } else {
        printf("[*] Course with the number %u found, name: %s.\n", target_course->course_number,
               (*result_course)->course_name);
    }

    // Operations
    (*result_course)->required_course_number = target_course->required_course_number;

    return 0;
}

int update_course_credit(struct CourseTable *course_table, struct Course *target_course) {
    // Only course_number in target_course is searched, other elements in target_course are ignored.
    struct Course **result_course = bsearch(&target_course, course_table->data, course_table->last_available,
                                            sizeof(struct Course *), compare_course);
    if (result_course == NULL) {
        printf("[!] Course with the number %u not found!\n", target_course->course_number);
    } else {
        printf("[*] Course with the number %u found, name: %s.\n", target_course->course_number,
               (*result_course)->course_name);
    }

    // Operations
    (*result_course)->credit = target_course->credit;

    return 0;
}

int select_course_number(struct CourseTable *course_table, struct Course *target_course) {
    struct Course **result_course = bsearch(&target_course, course_table->data, course_table->last_available,
                                            sizeof(struct Course *), compare_course);
    if (result_course == NULL) {
        printf("[!] Course with the number %u not found!\n", target_course->course_number);
        return -1;
    } else {
        printf("[*] Course with the number %u found, name: %s.\n", target_course->course_number,
               (*result_course)->course_name);
    }

    return 0;
}

int select_course_name(struct CourseTable *course_table, struct Course *target_course) {
    struct Course **result_course = &course_table->data[0];
    struct Course **last_table_entry = &(course_table->data[course_table->last_available - 1]);
    int found = 0;

    while (result_course <= last_table_entry) {
        if (strcmp((*result_course)->course_name, target_course->course_name) == 0) {
            printf("[*] Course with the name %s found, course number: %u.\n", target_course->course_name,
                   (*result_course)->course_number);
            found = 1;
        }
        ++result_course;
    }
    if (found == 0) {
        printf("[*] Course with the name %s not found.\n", target_course->course_name);
        return -1;
    }

    return 0;
}



