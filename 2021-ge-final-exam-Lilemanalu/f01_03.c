// 12S20017 - Lile Asima Manalu
// 12S20024 - Sandro Sinaga

#include "custom.h"
#include "repository.h"
#include "transaction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv){
  // codes
  char input[101];
  char cinput[101];
  input[0] = '\0';
  cinput[0] = '\0';
  char *separator = "#";

  //sentinel to track the number of transaction
  unsigned short int transaction_size = 0;

  //the array of transaction(dynamic)
  struct transaction_t *transactions = NULL;

  //loop
  while (1){
    //read input
    get_string(input, 100);
    strcpy(cinput, input);

    //tokenize
    char *command = strtok(cinput, separator);

    if (strcmp(command, "---") == 0){
      break;
    }

    //identify transaction
    if (strcmp(command, "register-transaction") == 0){
      //do the instruction
      // no.1 register transaction
      //more tokenize
      char *stype = strtok(NULL, separator);
      char *samount = strtok(NULL, separator);
      char *title = strtok(NULL, separator);

      //convert
      enum type_t type = get_type(stype);
      unsigned short int amount = atoi(samount);

      struct transaction_t new_transaction = create_transaction(title, amount, type);

      //register
      transaction_size = register_transaction(&transactions, transaction_size, new_transaction);
    } else if (strcmp(command, "print-income-transactions") == 0){
      //do the instruction
      //no.2 print-income-transaction
      print_income_transactions(transactions, transaction_size);
    } else if (strcmp(command, "print-expense-transactions") == 0){
      //do the instruction
      //no.3 print-expense-transaction
      print_expence_transactions(transactions, transaction_size);
    } else if (strcmp(command, "print-summary") == 0){
      //do the instruction
      //no.4 print-summary
      print_summary(transactions, transaction_size);
    }
  }

  //no.5 writing to repo
  return 0;
}
