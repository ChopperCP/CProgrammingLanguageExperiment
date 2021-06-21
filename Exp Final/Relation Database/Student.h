//
// Created by win10 on 2021/6/19.
//

#ifndef RELATION_DATABASE_STUDENT_H
#define RELATION_DATABASE_STUDENT_H

#define MAX_STUDENT_TABLE_ENT_CNT 2000

#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "Student_Course.h"

struct Student {
    unsigned int student_number;
    char student_name[30];
    char gender[10];
    unsigned int age;
    char school[100];
};

struct StudentTable {
    char type[5];       // Identify table type
    unsigned int last_available;    // Last available index
    struct Student *data[MAX_STUDENT_TABLE_ENT_CNT];
};

struct StudentTable init_student_table();

int add_student(struct StudentTable *table, struct Student *student);

int remove_student(struct StudentTable *student_table, struct StudentCourseTable *student_course_table,
                   struct Student *target_student);

int update_student_name(struct StudentTable *student_table, struct Student *target_student);

int update_student_gender(struct StudentTable *student_table, struct Student *target_student);

int update_student_age(struct StudentTable *student_table, struct Student *target_student);

int update_student_school(struct StudentTable *student_table, struct Student *target_student);

int select_student_number(struct StudentTable *student_table, struct Student *target_student);
int select_student_name(struct StudentTable *student_table, struct Student *target_student);

#endif //RELATION_DATABASE_STUDENT_H
