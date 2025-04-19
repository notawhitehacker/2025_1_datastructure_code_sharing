


#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "parenthesis_matching.h"

parenthesis_expr_t* new_expression(char* expr) {
	parenthesis_expr_t* pex =
		(parenthesis_expr_t*)malloc(sizeof(parenthesis_expr_t));

	pex->p_expr = expr;
	pex->matching = NULL;
	pex->size = sizeof(expr)/sizeof(char);
	return p_ex;
}

void parenthesis_matching(parenthesis_expr_t* pex) {
	stack_t* s = new_stack(pex->size, NULL);
	int* p_index;
	for(int i=0 ; i<pex->size ; i++) {
		if(pex->p_expr[i] == '(') {
			p_index = (int*)malloc(sizeof(int));
			*p_index = i;
			s.push_stack(s, p_index);
		} else if(pex->p_expr[i] == ')') {
		




parenthesis_expr_t* postfix_mode(parenthesis_expr_t* pex)



/*
parenthesis_expr_t* new_expression(char* expr);

void parenthesis_matching(parenthesis_expr_t* p_ex);
parenthesis_expr_t* postfix_mode(parenthesis_expr_t* pex);
*/

/*
#ifndef STACK_H
#define STACK_H

typedef struct stack_t {
    void** data;
    int size;
    int top;

    void (*print)(void*);
} stack_t;


stack_t* new_stack(int size, void (*print)(void*));
void delete_stack(stack_t* stack);

void push_stack(stack_t* stack, void* item);
void* pop_stack(stack_t* stack);

void print_stack(stack_t* stack, char* name);

int stack_is_empty(stack_t* stack);
int stack_is_full(stack_t* stack);

#endif
*/
