// 12S20017 - Lile Asima Manalu
// 12S20031 - Daniel Andres Simangunsong

#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENT 2

int main(int _argc, char **_argv){

  int i;
  struct option_t opt[100];
  struct option_t create_option();{
    struct option_t opt[100];
    for (i = 0; i < 100; i++){
      opt[i] = create_option();
      strcpy(opt[i].element1, "");
      strcpy(opt[i].element2, "");
      strcpy(opt[i].element3, "");
      strcpy(opt[i].element4, "");
      strcpy(opt[i].element5, "");
      strcpy(opt[i].input, "");
    }
  }
  
  char *token;
  char none[5] = "---";
  struct student_t *students = NULL;
  struct course_t *courses = NULL;
  struct enrollment_t *enrollments = NULL; 
  int a = 0;
  int b = 0;
  int c = 0; 
  students = malloc(sizeof(struct student_t) * a);
  courses = malloc(sizeof(struct course_t) * b);
  enrollments = malloc (sizeof(struct enrollment_t) * c); 
  short int next_student_index = 0;
  short int next_course_index = 0;
  short int next_enrollment_index = 0;

  for (i = 0; i < 100; i++){
    char action[100] = "";
    short int x = 0;
    action[0] = '\0';
    while (1){
      char d = '\0';
      d = getchar();
      if (d != '\r' && d != '\n'){
        action[x] = d;
        action[++x] = '\0';
      } else {
        if (d == '\r'){
          continue;
        }

        if (d == '\n'){
          break;
        };
      }
      
      if (strcmp(action, "---") == 0){
        i = 100;
        break;
      }
    }
    
    strcpy(opt[i].input, action);
    token = strtok(opt[i].input, "#");
    int y = 0;
    while (token != NULL){
      if (y == 0){
        strcpy(opt[i].element1, token);
        token = strtok(NULL, "#");
        y = y + 1;
      }
      else if (y == 1){
        strcpy(opt[i].element2, token);
        token = strtok(NULL, "#");
        y = y + 1;
      }
      else if (y == 2){
        strcpy(opt[i].element3, token);
        token = strtok(NULL, "#");
        y = y + 1;
      }
      else if (y == 3){
        strcpy(opt[i].element4, token);
        token = strtok(NULL, "#");
        y = y + 1;
      }
      else if (y == 4){
        strcpy(opt[i].element5, token);
        token = strtok(NULL, "#");
        y = y + 1;
      }
    }
  }

  char student_data[20] = "create-student";
  char students_data[20] = "print-students";
  char course_data[20] = "create-course";
  char courses_data[20] = "print-courses";
  char enrollment_data[20] = "create-enrollment";
  char enrollments_data[20] = "print-enrollments";
  char slash[20] = "---";
  char theyear[20] = "2020";
  
  for (i = 0; i < 100; i++){
    if (strcmp(opt[i].element1, "create-student") == 0 && strcmp(opt[i].element4, "2020") == 0){
      if (students == NULL){
        a = a + 1;
        students = malloc(sizeof(struct student_t) * a);
        students[next_student_index++] = create_student(opt[i].element2, opt[i].element3, opt[i].element4, opt[i].element5);
      } else {
        a = a + 1;
        students = realloc(students, sizeof(struct student_t) * a);
        students[next_student_index++] = create_student(opt[i].element2, opt[i].element3, opt[i].element4, opt[i].element5);
        }
    } else if(strcmp(opt[i].element1, "print-students") == 0){
        print_students(students, next_student_index);
    } else if(strcmp(opt[i].element1, "---") == 0){
        i = 100;
    } else if(strcmp(opt[i].element1, "create-course") == 0){

      enum grade_t _element = GRADE_NONE;
      if (strcmp(opt[i].element5, "A") == 0){
        _element = GRADE_A;
      }
      else if (strcmp(opt[i].element5, "AB") == 0){
        _element = GRADE_AB;
      }
      else if (strcmp(opt[i].element5, "B") == 0){
        _element = GRADE_B;
      }
      else if (strcmp(opt[i].element5, "BC") == 0){
        _element = GRADE_BC;
      }
      else if (strcmp(opt[i].element5, "C") == 0){
        _element = GRADE_C;
      }
      else if (strcmp(opt[i].element5, "D") == 0){
        _element = GRADE_D;
      } else{
        _element = GRADE_E;
      }
      if (courses == NULL){
        b = b + 1;
        courses = malloc(sizeof(struct course_t) * b);
        courses[next_course_index++] =
            create_course(opt[i].element2, opt[i].element3, atoi(opt[i].element4), _element);
      } else {
        b = b + 1;
        courses = realloc(courses, sizeof(struct course_t) * b);
        courses[next_course_index++] =
            create_course(opt[i].element2, opt[i].element3, atoi(opt[i].element4), _element);
      }
    } else if(strcmp(opt[i].element1, "print-courses") == 0){
      print_courses(courses, next_course_index);
    }
    else if (strcmp(opt[i].element1, "find-student-by-id") == 0)
    {
      find_student_by_id(students, next_student_index, opt[i].element2);
    }
    else if (strcmp(opt[i].element1, "find-course-by-code") == 0)
    {
      find_course_by_code(courses, next_course_index, opt[i].element2);
    } else if (strcmp(opt[i].element1, "create-enrollment")==0){
      enum grade_t _element_grade;
      int j, k = 0;

      if(strcmp(opt[i].element5, "even")==0){
        _element_grade = SEMESTER_EVEN; 
      } else {
        _element_grade = SEMESTER_ODD; 
      }

      if (enrollments == NULL){
     do {
       if(strcmp(opt[i].element2, courses[j].code)==0 && strcmp(opt[i].element3, students[k].id) ==0){
           c += 1;
          enrollments = malloc(sizeof(struct enrollment_t) * c);
          enrollments[next_enrollment_index++] = create_enrollment(courses[j], students[k], opt[i].element4, _element_grade);
          j=100; 
         } else if(strcmp(opt[i].element2, courses[j].code)!=0) {
           j+=1;
         }else if (strcmp(opt[i].element3, students[k].id)!=0){
           k+=1;
         } 
       } while(k !=100); 
     } else if (strcmp(opt[i].element2, courses[j].code) ==0 && strcmp(opt[i].element3, students[k].id) ==0){
       int j, k = 0;
       c += 1;
       enrollments = realloc(enrollments, sizeof(struct enrollment_t) * c);
       enrollments[next_enrollment_index++] = create_enrollment(courses[j], students[k], opt[i].element4, _element_grade);
       j = 100;
        if (strcmp(opt[i].element2, courses[j].code) != 0){
          j += 1;
        } else if (strcmp(opt[i].element3, students[k].id) != 0){
          k += 1;
        }
      } while (k != 100);
    } else if(strcmp(opt[i].element1, "print-enrollments") == 0){
      print_enrollments(enrollments, next_enrollment_index);
    }
  }

  return 0;
}
