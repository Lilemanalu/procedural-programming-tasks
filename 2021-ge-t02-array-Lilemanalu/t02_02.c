// 12S20017 - Lile Manalu
// 12S20031 - Daniel Andres Simangunsong

#include <stdio.h>

int main(int _argv, char **_argc) {
  int n;
  scanf("%d", &n);
  int number[n];
  int j;

  for(j=0;j<=n-1;j++){
    scanf("%d", &number[j]);
  }  

  for(j=0;j<=n-1;j++){
    printf("%d", number[j]);
    if(j<n-1){
      printf(",");
    }
  }
  printf("\n");

  if(n%2 == 0){
    for(j=0; j<=n/2 -1; j++){
      printf("%d", number[j]);
      if(j< n/2){
        printf(",");
      }
      printf("%d", number[n-(j+1)]);
      if(j< (n/2)-1){
        printf(",");
      }
    }
  } else{
    for(j=0; j<=(n-1)/2; j++){
      printf("%d", number[j]);
      if(j< (n-1)/2){
        printf(",");
      }
      if(j<=(n-1)/2 -1){
        printf("%d", number[n-(j+1)]);
        printf(",");
      }
    }
  }

  return 0;
}
