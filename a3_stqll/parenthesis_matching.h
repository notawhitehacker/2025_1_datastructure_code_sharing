
#ifndef PARENTHESIS_MATCHING_H
#define PARENTHESIS_MATCHING_H

#include "stack.h"

typedef struct {
    char* p_expr;
    int[2]* matching;
    int size;
} parenthesis_expr_t;

parenthesis_expr_t* new_expression(char* expr);

void parenthesis_matching(parenthesis_expr_t* p_ex);
parenthesis_expr_t* postfix_mode(parenthesis_expr_t* pex);




#endif

