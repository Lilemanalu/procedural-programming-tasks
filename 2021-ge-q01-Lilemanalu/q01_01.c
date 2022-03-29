// 12S20017 - Lile Manalu
// 12S20031 - Daniel Simangunsong

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//membuat structure
typedef struct {
  char name[20];
  char value[20];
  char type[15];
  char temp[20];
} transaction ;

int main(int _argc, char **_argv) {
  //menerima input berupa argument
  int n;
  for( int c = 0; c < _argc; c++) {
    n = atoi(_argv[c]);}
  
  //men-declare structure dengan variabel myTransaction
  transaction myTransaction[n] ;

  int i;
  for(i= 0;i< n;i++){
    char input[100];
    short int j = 0;
    input[0] = '\0';

    //menerima input transaksi
    while(1) {
      char c = getchar();
      if (c != '\r' && c != '\n') {
        input[j] = c;
        input[++j] = '\0';
      }  
      else {
        if (c == '\r') {
          continue;
        }
      if (c == '\n') {
        break;
        };
      } 
    }
  
    //memecah string dan menetapkan ke variabel yang sesuai
    int b = 0;
    char *token; 
    strcpy(myTransaction[i].temp, input);
    token = strtok(myTransaction[i].temp,"#");
    while(token != NULL){
      if (b==0){
        strcpy(myTransaction[i].type, token);
        token = strtok(NULL, "#");
        b += 1;
      } else if ( b == 1){
        strcpy(myTransaction[i].value, token);
        token = strtok(NULL, "#");
        b += 1;
      }else if (b == 1){
        strcpy(myTransaction[i].value, token);
        token = strtok(NULL, "#");
        b += 1;
      }else{
        strcpy(myTransaction[i].name, token);
        token = strtok(NULL, "#");
      }
    }
  }

  //menampilkan semua transaksi yang diterima
  for(i=0;i<n;i++){ //income
    if(strcmp(myTransaction[i].type, "income")==0){
      printf("%s;%s;%s\n",myTransaction[i].name,myTransaction[i].value, myTransaction[i].type );
    } 
  }
  for(i=0;i<n;i++){ //expense
    if(strcmp(myTransaction[i].type, "expense")==0){
      printf("%s;%s;%s\n",myTransaction[i].name,myTransaction[i].value, myTransaction[i].type );
    } 
  }

  //penjumlahan income dan expense
  int total_income = 0;
  int total_expense = 0;
  for(i=0;i<n;i++){
    if(strcmp(myTransaction[i].type, "income")==0){
      total_income += atoi(myTransaction[i].value);
    } else{
      total_expense += atoi(myTransaction[i].value);
    }
  }

  int total = total_income - total_expense;

  //menentukan apakah deficit, surplus atau balanced
  char summary[15];
  summary[0]='\0'; 
  if(total_income > total_expense){
    strcpy(summary, "surplus"); 
  } else if (total_income < total_expense){
    strcpy(summary,"deficit");
  } else {
    strcpy(summary, "balanced"); 
  }

  printf("%i %s\n", total, summary);

  return 0;
}
