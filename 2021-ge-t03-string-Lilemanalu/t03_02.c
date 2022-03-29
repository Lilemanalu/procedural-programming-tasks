// 12S20017 - Lile Manalu
// 12S20031 - Daniel Andres Simangunsong

#include <stdio.h>

int main(int _argv, char **_argc) {
  char ASCII[20];
  int i = 0;
  gets(ASCII);
  while(ASCII[i]){
    if(ASCII[i]<100){
      printf("0%d", ASCII[i]);
      i++ ;
    } else{
      printf("%d", ASCII[i]);
      i++;
    }
  }
  return 0;
}
