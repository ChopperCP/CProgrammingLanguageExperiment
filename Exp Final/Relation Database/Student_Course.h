//
// Created by win10 on 2021/6/19.
//

#ifndef RELATION_DATABASE_STUDENT_COURSE_H
#define RELATION_DATABASE_STUDENT_COURSE_H

#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Student.h"
#include "Course.h"

#define MAX_STUDENT_COURSE_TABLE_ENT_CNT 20000

struct StudentCourse {
    unsigned int student_number;
    unsigned int course_number;
    double grade;
};

struct StudentCourseTable {
    char type[5];       // Identify table type
    unsigned int last_available;    // Last available index
    struct StudentCourse *data[MAX_STUDENT_COURSE_TABLE_ENT_CNT];
};

struct StudentCourseTable init_student_course_table();

int compare_student_course(const void *lhs, const void *rhs);

int update_grade(struct StudentCourseTable *student_course_table, struct Student *target_student,
                 struct Course *target_course, double grade);

int select_student_course(struct StudentCourseTable *student_course_table, struct Student *target_student,
                          struct Course *target_course);

#endif //RELATION_DATABASE_STUDENT_COURSE_H
