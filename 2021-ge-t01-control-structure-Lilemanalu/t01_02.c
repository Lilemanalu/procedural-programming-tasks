// 12S20017 - Lile Manalu
// 12S20031 - Daniel Simangunsong

#include <stdio.h>

int main(int _argv, char **_argc) {
  int x1, x2, t1, t2, total ;
  scanf( "%d" , &x1);
  scanf( "%d" , &x2);
  if (x1 > x2) {
    if (x1 % 2 == 1) {
      x1 = x1 +1 ;
    } else {
      t1 == 0 ;
    }
    if (x1% 2 == 0 ){
      t1 = (x1 -1) * 3 ;
    }
    if (x2 % 2 == 1 ) {
      x2 = x2 + 1 ;
    } else {
      t2 == 0 ;
    }
    t2 = (x2 *3 );
  } else {
    if (x1 % 2 == 1) {
      x1 = x1 +1 ;
      t1 = (x1/2 + (x1/2 -1)) * 3 ;
    } else {
      t1 == 0 ;      
    }
    if ( x1 % 2 == 0) {
      t1 = (x1/2 + (x1/2 -1)) * 3 ;
    }


    if (x2 % 2 == 1 ) {
      x2 == x2 +1;
    } else  {
      t2 == 0 ;
    }
    t2 = (x2/2 + x1/2)  * 3 ;

  }
  if (x1 == 0 && x2 == 0) {
    t1 = t2 = 0;
  }

  printf("%d\n" ,t1);
  printf("%d\n" ,t2);
  total = t1 + t2;
  printf("%d\n", total);
  return 0;
}