// 12S20017 - Lile Manalu
// 12S20024 - Sandro Sinaga

#include "repository.h"
#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

short int load_students_from_repository(struct student_t **_students) {
 FILE *repository = fopen(DEFAULT_STUDENT_REPOSITORY, "r");

 if(repository == EOF) {
   printf("failed to close the stream.\n");
   return -1;
 }

  char input[101];
  char cinput[101];
  const char *separator = "|";

  unsigned short int student_size = 0;

  while(1){
    get_line(repository,input, 100);
    strcpy(cinput, input);

 char *id = strtok(cinput, separator);
    char *name = strtok(NULL, separator);
    char *year = strtok(NULL, separator);
    char *study_program = strtok(NULL, separator);
    char *sgpa = strtok(NULL, separator);
    float gpa = atof(sgpa);
  
  }

    short int student_index = get_student_index_by_id(*_students, student_size, id);

    if(student_index > -1){
      continue;
    }

    struct student_t new_student = create_student(id, name, year, study_program);
    new_student.gpa = gpa;

    student_index;
    if(student_index == 1){
     *_students = malloc(sizeof(struct student_t) *student_size);
      } else {
      *_students = realloc(*_students, sizeof(struct student_t) *student_size); 
      }

      (*_student)[student_size -1 ] = new_student;
    }

    short int closing_code = fclose(repository);
    if(closing_code !=0){
      printf("failed to close the stream.\n");
      return -2;
    }

  return student_size;
}
short int load_courses_from_repository(struct course_t **_courses) { return 0; }
short int load_enrollments_from_repository(struct enrollment_t **_enrollments,
                                           struct course_t *_courses,
                                           unsigned short int _course_size,
                                           struct student_t *_students,
                                           unsigned short int _student_size) {
  return 0;
}
void save_courses_to_repository(struct course_t *_courses,
                                unsigned short int _course_size) {}
void save_students_to_repository(struct student_t *_students,
                                 unsigned short int _student_size) {}
void save_enrollments_to_repository(struct enrollment_t *_enrollments,
                                    unsigned short int _enrollment_size) {}
