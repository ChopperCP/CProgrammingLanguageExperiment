//
// Created by win10 on 2021/6/19.
//

#include "Student_Course.h"

int compare_student_course(const void *lhs, const void *rhs);

struct StudentCourseTable init_student_course_table() {
    struct StudentCourseTable table;
    strcpy(table.type, "SC");

    // Fill the table with 10000 demo entries
    srand((unsigned) time(NULL));
    for (int i = 1; i <= 10000; ++i) {
        // Init StudentCourse
        struct StudentCourse *demo_student_course = malloc(sizeof(struct StudentCourse));
        memset(demo_student_course, 0, sizeof(struct StudentCourse));

        demo_student_course->student_number = (rand() % 1000) + 1;        // 1-1000
        demo_student_course->course_number = (rand() % 50) + 1;           // 1-50
        demo_student_course->grade = rand() % 101;                        // 0-100

        // Fill the table
        table.data[i - 1] = demo_student_course;
        table.last_available = i;
    }

    // Sort the table.
    qsort(table.data, table.last_available, sizeof(struct StudentCourse *), compare_student_course);

    return table;
}

int compare_student_course(const void *lhs, const void *rhs) {
    unsigned int lhs_student_number = (*((struct StudentCourse **) lhs))->student_number;
    unsigned int rhs_student_number = (*((struct StudentCourse **) rhs))->student_number;
    return lhs_student_number - rhs_student_number;
}


int add_student_course(struct StudentCourseTable *table, struct StudentCourse *student_course) {
    if (table->last_available >= MAX_STUDENT_COURSE_TABLE_ENT_CNT) {
        printf("[!] Not enough space in the table.");
        return -1;
    }

    // Insert the student_course to the last place.
    table->data[table->last_available++] = student_course;
    // Sort the table.
    qsort(table->data, table->last_available, sizeof(struct StudentCourse *), compare_student_course);

    return 0;
}

int remove_student_course(struct StudentCourseTable *student_course_table, struct Student *target_student,
                          struct Course *target_course) {
    // Only student_number in target_student and course_number in target_course are searched, other elements in target_course are ignored.
    struct StudentCourse **result_student_course = &student_course_table->data[0];
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);
    while ((result_student_course <= last_table_entry) &&
           (((*result_student_course)->student_number != target_student->student_number) ||
            ((*result_student_course)->course_number != target_course->course_number))) {
        ++result_student_course;
    }
//    struct  StudentCourse** result_student_course=bsearch(&target_student,student_course_table->data,student_course_table->last_available,sizeof(struct StudentCourse*),compare_student_student_course);
    if (result_student_course > last_table_entry) {
        // Result not found
        result_student_course = NULL;
    }

    if (result_student_course == NULL) {
        printf("[!] Entry not found in SC\n");
        return -1;
    } else {
        // Operation
        struct StudentCourse **start = result_student_course;
        struct StudentCourse **end = result_student_course;
        struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);

        while ((*end)->course_number == (*result_student_course)->course_number) {
            printf("[*] Entry found, student number: %u, course number: %u, grade:%lf\n", (*end)->student_number,
                   (*end)->course_number, (*end)->grade);
            ++end;
        }
        // From start-end is the memory which will be cleaned.
        // Move the rest forward.
        while (end <= last_table_entry) {
            memcpy(start++, end++, sizeof(struct StudentCourse *));
        }
        student_course_table->last_available -= end - start;
    }

    return 0;
}

int update_grade(struct StudentCourseTable *student_course_table, struct Student *target_student,
                 struct Course *target_course, double grade) {
    // Only student_number in target_student and course_number in target_course are searched, other elements in target_course are ignored.
    struct StudentCourse **result_student_course = &student_course_table->data[0];
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);
    while ((result_student_course <= last_table_entry) &&
           (((*result_student_course)->student_number != target_student->student_number) ||
            ((*result_student_course)->course_number != target_course->course_number))) {
        ++result_student_course;
    }
//    struct  StudentCourse** result_student_course=bsearch(&target_student,student_course_table->data,student_course_table->last_available,sizeof(struct StudentCourse*),compare_student_student_course);
    if (result_student_course > last_table_entry) {
        // Result not found
        result_student_course = NULL;
    }

    if (result_student_course == NULL) {
        printf("[!] Entry not found in SC\n");
        return -1;
    } else {
        printf("[*] Entry found, student number: %u, course number: %u, grade:%lf\n", target_student->student_number,
               target_course->course_number, (*result_student_course)->grade);
        // Operation
        (*result_student_course)->grade = grade;
    }

    return 0;
}

int select_student_course(struct StudentCourseTable *student_course_table, struct Student *target_student,
                          struct Course *target_course) {
    struct StudentCourse **result_student_course = &student_course_table->data[0];
    struct StudentCourse **last_table_entry = &(student_course_table->data[student_course_table->last_available - 1]);
    while ((result_student_course <= last_table_entry) &&
           (((*result_student_course)->student_number != target_student->student_number) ||
            ((*result_student_course)->course_number != target_course->course_number))) {
        ++result_student_course;
    }
    if (result_student_course > last_table_entry) {
        // Result not found
        result_student_course = NULL;
    }

    if (result_student_course == NULL) {
        printf("[!] Entry not found in SC\n");
        return -1;
    } else {
        printf("[*] Entry found, student number: %u, course number: %u, grade:%lf\n", target_student->student_number,
               target_course->course_number, (*result_student_course)->grade);
        // Operation
    }

    return 0;
}