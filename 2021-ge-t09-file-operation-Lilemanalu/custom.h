// 12S20017 - Lile Manalu
// 12S20024 - Sandro Sinaga

#include "academic.h"

#ifndef CUSTOM_H
#define CUSTOM_H

// additional struct definitions

// additional enum definitions

// additional function prototypes
void get_string(char *_buffer, unsigned int _size);
void get_line(FILE *_stream, char *buffer, unsigned int _size);
enum grade_t get_grade(char *_grade);
enum semester_t get_semester(char *_semester);
char *semester_to_text(enum semester_t _semester);
short int get_course_index_by_code(struct course_t *_courses, unsigned short int _course_size, char *_code);
short int get_student_index_by_id(struct student_t *_students, unsigned short int _student_size, char *_id);


#endif
