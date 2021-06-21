//
// Created by win10 on 2021/6/19.
//

#ifndef RELATION_DATABASE_COURSE_H
#define RELATION_DATABASE_COURSE_H

#define MAX_COURSE_TABLE_ENT_CNT 100

#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "Course.h"
#include "Student_Course.h"

struct Course {
    unsigned int course_number;
    char course_name[100];
    unsigned int required_course_number;
    double credit;
};

struct CourseTable {
    char type[5];       // Identify table type
    unsigned int last_available;    // Last available index
    struct Course *data[MAX_COURSE_TABLE_ENT_CNT];
};

struct CourseTable init_course_table();

int remove_course(struct CourseTable *course_table, struct StudentCourseTable *student_course_table,
                  struct Course *target_course);

int update_course_name(struct CourseTable *course_table, struct Course *target_course);

int update_course_required_course_number(struct CourseTable *course_table, struct Course *target_course);

int update_course_credit(struct CourseTable *course_table, struct Course *target_course);

int select_course_number(struct CourseTable *course_table, struct Course *target_course);
int select_course_name(struct CourseTable *course_table, struct Course *target_course);


#endif //RELATION_DATABASE_COURSE_H
