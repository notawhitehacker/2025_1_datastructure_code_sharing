
#ifndef POLYNOMIAL_OF_LINKED_LIST_H
#define POLYNOMIAL_OF_LINKED_LIST_H

#include "linkedlist.h"

struct term_t {
	float coef;
	int deg;
};

typedef linked_list_t polynomial_t;
typedef struct term_t term_t;


polynomial_t* new_polynomial();

double fval_polynomial(polynomial_t* pol, int x);

polynomial_t* add_polynomial(polynomial_t* pol1, polynomial_t* pol2);
polynomial_t* subtract_polynomial(polynomial_t* pol1, polynomial_t* pol2);

void align_polynomial(polynomial_t* pol);

void print_term(void* t);
int compare_by_degree(void* t1, void* t2);

#endif
