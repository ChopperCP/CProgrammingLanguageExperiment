//
// Created by win10 on 2021/6/19.
//

#include "Student.h"

struct StudentTable init_student_table() {
    struct StudentTable table;
    strcpy(table.type, "S");

    // Fill the table with 1000 demo entries
    for (int i = 1; i <= 1000; ++i) {
        // Init student
        struct Student *demo_student = malloc(sizeof(struct Student));
        memset(demo_student, 0, sizeof(struct Student));      // Clean up the memory.

        demo_student->student_number = i;
        strcpy(demo_student->student_name, "ChopperCP");
        strcpy(demo_student->gender, "Male");
        demo_student->age = 21;
        strcpy(demo_student->school, "School of Intelligence Engineering Science");

        // Fill the table
        table.data[i - 1] = demo_student;
        table.last_available = i;
    }
    return table;
}

int compare_student(const void *lhs, const void *rhs) {
    unsigned int lhs_student_number = (*((struct Student **) lhs))->student_number;
    unsigned int rhs_student_number = (*((struct Student **) rhs))->student_number;
    return lhs_student_number - rhs_student_number;
}

int compare_student_student_course(const void *lhs, const void *rhs) {
    unsigned int lhs_student_number = (*((struct Student **) lhs))->student_number;
    unsigned int rhs_student_number = (*((struct StudentCourse **) rhs))->student_number;
    return lhs_student_number - rhs_student_number;
}

int add_student(struct StudentTable *table, struct Student *student) {
    if (table->last_available >= MAX_STUDENT_TABLE_ENT_CNT) {
        printf("[!] Not enough space in the table.");
        return -1;
    }

    // Insert the student to the last place.
    table->data[table->last_available++] = student;
    // Sort the table.
    qsort(table->data, table->last_available, sizeof(struct Student *), compare_student);

    return 0;
}

void _clean_Student_from_StudentTable(struct Student **result_student, struct StudentTable *student_table) {
    struct Student **start = result_student;
    struct Student **end = result_student;
    struct Student **last_table_entry = &(student_table->data[student_table->last_available - 1]);

    while ((*end)->student_number == (*result_student)->student_number) {
        printf("[*] Entry found, student number: %u\n",(*end)->student_number);
        ++end;
    }
    // From start-end is the memory which will be cleaned.
    // Move the rest forward.
    while (end <= last_table_entry) {
        memcpy(start++, end++, sizeof(struct Student *));
    }
    student_table->last_available -= end - start;
}

void _clean_Student_from_StudentCourseTable(struct StudentCourse **result_student_course,
                                            struct StudentCourseTable *student_course_table) {
    struct StudentCourse **start = result_student_course;
    struct StudentCourse **end = result_student_course;
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);

    while ((*end)->student_number == (*result_student_course)->student_number) {
        printf("[*] Entry found, student number: %u, course number: %u\n",(*end)->student_number,(*end)->course_number);
        ++end;
    }
    // From start-end is the memory which will be cleaned.
    // Move the rest forward.
    while (end <= last_table_entry) {
        memcpy(start++, end++, sizeof(struct StudentCourse *));
    }
    student_course_table->last_available -= end - start;
}

int remove_student(struct StudentTable *student_table, struct StudentCourseTable *student_course_table,
                   struct Student *target_student) {
    // Only student_number in target_student is searched, other elements in target_student are ignored.
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    // Remove student from student_table
    _clean_Student_from_StudentTable(result_student, student_table);

    // Can't use binary search in SC because there are more than 1 entry which has the same student_number.
    struct StudentCourse **result_student_course = &student_course_table->data[0];
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);
    while ((result_student_course <= last_table_entry) &&
           ((*result_student_course)->student_number != target_student->student_number)) {
        ++result_student_course;
    }
//    struct  StudentCourse** result_student_course=bsearch(&target_student,student_course_table->data,student_course_table->last_available,sizeof(struct StudentCourse*),compare_student_student_course);
    if (result_student_course > last_table_entry) {
        // Result not found
        result_student_course = NULL;
    }
    if (result_student_course == NULL) {
        printf("[*] Student with the number %u not found in SC\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found in SC, course number: %u.\n", target_student->student_number,
               (*result_student_course)->course_number);
        // Remove student from student_course table.
        _clean_Student_from_StudentCourseTable(result_student_course, student_course_table);
    }

    return 0;
}

int update_student_name(struct StudentTable *student_table, struct Student *target_student) {
    // Only student_number in target_student is searched, other elements in target_student are ignored.
    // From student_table
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    // Operations
    strcpy((*result_student)->student_name, target_student->student_name);

    return 0;
}

int update_student_gender(struct StudentTable *student_table, struct Student *target_student) {
    // Only student_number in target_student is searched, other elements in target_student are ignored.
    // From student_table
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    // Operations
    strcpy((*result_student)->gender, target_student->gender);

    return 0;
}

int update_student_age(struct StudentTable *student_table, struct Student *target_student) {
    // Only student_number in target_student is searched, other elements in target_student are ignored.
    // From student_table
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    // Operations
    (*result_student)->age = target_student->age;

    return 0;
}

int update_student_school(struct StudentTable *student_table, struct Student *target_student) {
    // Only student_number in target_student is searched, other elements in target_student are ignored.
    // From student_table
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    // Operations
    strcpy((*result_student)->school, target_student->school);

    return 0;
}

int select_student_number(struct StudentTable *student_table, struct Student *target_student) {
    struct Student **result_student = bsearch(&target_student, student_table->data, student_table->last_available,
                                              sizeof(struct Student *), compare_student);
    if (result_student == NULL) {
        printf("[!] Student with the number %u not found!\n", target_student->student_number);
        return -1;
    } else {
        printf("[*] Student with the number %u found, name: %s.\n", target_student->student_number,
               (*result_student)->student_name);
    }

    return 0;
}

int select_student_name(struct StudentTable *student_table, struct Student *target_student) {
    struct Student **result_student = &student_table->data[0];
    struct Student **last_table_entry = &(student_table->data[student_table->last_available - 1]);
    int found = 0;

    while (result_student <= last_table_entry) {
        if (strcmp((*result_student)->student_name,target_student->student_name)==0) {
            printf("[*] Student with the name %s found, student number: %u.\n", target_student->student_name,
                   (*result_student)->student_number);
            found = 1;
        }
        ++result_student;
    }
    if (found == 0) {
        printf("[*] Student with the name %s not found.\n", target_student->student_name);
        return -1;
    }

    return 0;
}


