cmake_minimum_required(VERSION 3.19)
project(Relation_Database C)

set(CMAKE_C_STANDARD 99)

add_executable(Relation_Database main.c Student.h Course.h Student_Course.h student.c course.c student_course.c import_export.c import_export.h  cJSON.c cJSON.h)

