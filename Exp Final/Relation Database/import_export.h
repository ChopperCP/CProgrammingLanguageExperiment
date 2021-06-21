//
// Created by win10 on 2021/6/20.
//

#ifndef RELATION_DATABASE_IMPORT_EXPORT_H
#define RELATION_DATABASE_IMPORT_EXPORT_H

#include <stdio.h>

#define MAX_FILE_BUFFER_SIZE 4*1024*1024    // 4MiB

#include "cJSON.h"
#include "Student.h"
#include "Course.h"
#include "Student_Course.h"

char *create_monitor_with_helpers(void);
int supports_full_hd(const char * const monitor);

int export_student_table(char* path, struct StudentTable* student_table);
int import_student_table(char* path, struct StudentTable* student_table);

int export_course_table(char *path, struct CourseTable *course_table);
int import_course_table(char *path, struct CourseTable *course_table);

int export_student_course_table(char *path, struct StudentCourseTable *student_course_table);
int import_student_course_table(char *path, struct StudentCourseTable *student_course_table);

#endif //RELATION_DATABASE_IMPORT_EXPORT_H
