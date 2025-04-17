
#ifndef PARENTHESIS_MATCHING_H
#define PARENTHESIS_MATCHING_H

#include "stack.h"

enum FIX_MODE {
    PREFIX=0, INFIX, POSTFIX
}

typedef struct {
    char* expression;
    int size;
} expression_t;

expression_t* new_expression(char* expr);

expression_t* convert_mode(char* expr, enum FIX_MODE mode);



#endif

