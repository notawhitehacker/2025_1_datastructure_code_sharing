
#ifndef POLYNOMIAL_OF_ARRAY_H
#define POLYNOMIAL_OF_ARRAY_H

#define LIMIT_OF_DEGREE 20

struct term_t {
	float coef;
	int deg;
};

typedef struct term_t term_t;
typedef term_t* polynomial_t;

polynomial_t new_polynomial();

double fval_polynomial(polynomial_t pol, int x);

polynomial_t add_polynomial(polynomial_t pol1, polynomial_t pol2);
polynomial_t subtract_polynomial(polynomial_t pol1, polynomial_t pol2);

void print_polynomial(polynomial_t pol, char* name);

#endif
