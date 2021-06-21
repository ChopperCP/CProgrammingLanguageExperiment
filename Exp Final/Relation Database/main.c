#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Student.h"
#include "Course.h"
#include "Student_Course.h"
#include "import_export.h"


int main() {
    clock_t begin, end;
    begin = clock();
    double lapse = 0;

    struct StudentTable student_table = init_student_table();
    struct CourseTable course_table = init_course_table();
    struct StudentCourseTable student_course_table = init_student_course_table();

    struct Student target_student;
    target_student.student_number = 1;
    // Test update student
//    target_student.age=10000;
    strcpy(target_student.student_name, "ChopperCP");
//    strcpy(target_student.gender,"Unknown");
//    strcpy(target_student.school,"JNU");
//
//    update_student_age(&student_table,&target_student);
//    update_student_name(&student_table,&target_student);
//    update_student_gender(&student_table,&target_student);
//    update_student_school(&student_table,&target_student);

    // Test remove student
//    remove_student(&student_table,&student_course_table,&target_student);


    // Test remove course
    struct Course target_course;
    target_course.course_number = 1;
//    remove_course(&course_table,&student_course_table,&target_course);

    // Test SC update
//    update_grade(&student_course_table,&target_student,&target_course,99);

    // Test select student
//    select_student_number(&student_table,&target_student);
//    select_student_name(&student_table,&target_student);

    // Test json
//    char * json=create_monitor_with_helpers();
//    supports_full_hd(json);

    export_student_table("D:\\stuff\\student_table.json",&student_table);
    struct StudentTable imported_student_table;
    import_student_table("D:\\stuff\\student_table.json", &imported_student_table);

    export_course_table("D:\\stuff\\course_table.json",&course_table);
    struct CourseTable imported_course_table;
    import_course_table("D:\\stuff\\course_table.json", &imported_course_table);

    export_student_course_table("D:\\stuff\\student_course_table.json",&student_course_table);
    struct StudentCourseTable imported_student_course_table;
    import_student_course_table("D:\\stuff\\student_course_table.json", &imported_student_course_table);


    end = clock();
    lapse = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("[*] Execution time: %lf s.", lapse);

    return 0;
}
