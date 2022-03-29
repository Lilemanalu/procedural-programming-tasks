// 12S20017 - Lile Manalu
// 12S20031 - Daniel Simangunsong

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct asmnt_component_t {
    char name[41];
    float weight;
    float score;
  };

  struct asmnt_component_t create_component(char *_name, int _weight, int _score ){
    struct asmnt_component_t component;
    strcpy(component.name, _name);
    component.weight = _weight;
    component.score = _score;

    return (component);
  }

  void get_string(char *in, unsigned int _size) {
    char c = '\0';
    unsigned int x = 0;
    in[x] = '\0';

    while((c = getchar()) != EOF && x < _size){
      if (c == '\r') {
        continue;
      }
      if (c == '\n'){
        break;
      }
      in[x++] = c;
      in[x] = '\0';
    }
  }

int main(int _argc, char **_argv) {
  short k = 0;
  if (_argc > 1){
    k = atoi(_argv[1]);
  }

  struct asmnt_component_t components[k];

  for (short x = 0 ; x < k ; x++) {
    char input[101];
    char input_temp[101];
    input[0] = '\0';

    get_string(input, 100);
    strcpy(input_temp, input);

    char *name;
    char *sweight;
    char *sscore;
    name = strtok(input_temp, "#");
    sweight = strtok(NULL, "#");
    sscore = strtok(NULL, "#");

    float weight = atof(sweight);
    float score = atof(sscore);
    components[x]= create_component(name, weight , score);
   
  }
 
  for (short x = 0 ; x < k ; x++) {
    printf("%s;%.0f;%.0f\n", components[x].name, components[x].weight, components[x].score);
  }

  float total_scores[k];
  float total=0;

  for (short x = 0 ; x < k ; x++) {
    total_scores[x] = (components[x].weight / 100) * components[x].score;
    total = total + total_scores[x];
  }

  printf("%.1f\n", total);
  if( total >= 50.0){
    printf("passed\n");
  } else {
    printf("failed\n");
  }

  return 0;
}
