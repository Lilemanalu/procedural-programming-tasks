// 12S20017 - Lile Asima Manalu
// 12S20024 - Sandro Sinaga

#include "transaction.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct transaction_t
create_transaction(char *_title, unsigned short int _amount, enum type_t _type){
    struct transaction_t transaction;
    strcpy(transaction.title, _title);
    transaction.amount = _amount;
    transaction.type = _type;

    return transaction;
}

short int register_transaction(struct transaction_t **_transactions,
                               unsigned short int _transaction_size,
                               struct transaction_t _transaction){
    _transaction_size++;
    if (_transaction_size == 1){
        // malloc
        *_transactions = malloc(sizeof(struct transaction_t) * _transaction_size);
    } else{
        // realloc
        *_transactions = realloc(*_transactions, sizeof(struct transaction_t) * _transaction_size);
    }
    // add the new transaction into the array
    (*_transactions)[_transaction_size - 1] = _transaction;

    return _transaction_size;
}

enum type_t get_type(char *_stype){
    if (strcmp(_stype, "income") == 0){
        return TYPE_INCOME;
    }

    return TYPE_EXPENSE;
}

char *type_to_text(enum type_t _type){
    char *text = malloc(8);
    text[0] = '\0';

    switch (_type){
    case TYPE_EXPENSE:
        strcpy(text, "expense");
        break;
    default:
        strcpy(text, "income");
    }
    return text;
}

void print_income_transactions(struct transaction_t *_transactions,
                               unsigned short int _transaction_size){
    for (int x = 0; x < _transaction_size; x++){
        char *type = type_to_text(_transactions[x].type);
        if (strcmp(type, "income") == 0){
            printf("%s;%d;%s\n", _transactions[x].title, _transactions[x].amount, type);
        }
    }
}

void print_expense_transactions(struct transaction_t *_transactions,
                                unsigned short int _transaction_size){
    for (int x = 0; x < _transaction_size; x++){
        char *type = type_to_text(_transactions[x].type);
        if (strcmp(type, "expense") == 0){
            printf("%s;%d;%s\n", _transactions[x].title, _transactions[x].amount, type);
        }
    }
}

void print_summary(struct transaction_t *_transactions,
                   unsigned short int _transaction_size){
    int total_income = 0;
    int total_expense = 0;
    for (int x = 0; x < _transaction_size; x++){
        char *type = type_to_text(_transactions[x].type);
        if (strcmp(type, "income") == 0){
            total_income += _transactions[x].amount;
        } else if (strcmp(type, "expense") == 0){
            total_expense += _transactions[x].amount;
        }
    }
    
    if (total_income < total_expense){
        int total = total_expense - total_income;
        printf("%d %s\n", total, "deficit");
    } else if (total_income > total_expense){
        int total = total_income - total_expense;
        printf("%d %s\n", total, "surplus");
    }else{
       int total = 0; 
        printf("%d %s\n", total, "balanced");
    }
        
}
