
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "polynomial_arr.h"

polynomial_t new_polynomial() {
	polynomial_t pol = (polynomial_t)malloc(sizeof(term_t)*(LIMIT_OF_DEGREE+1));
	for(int i=0 ; i<=LIMIT_OF_DEGREE ; i++) {
		pol[i].coef = 0;
		pol[i].deg = i;
	}
	return pol;
}

double fval_polynomial(polynomial_t pol, int x) {
	double result = 0;
	for(int i=0 ; i<=LIMIT_OF_DEGREE ; i++) {
		result += pol[i].coef * pow(x, pol[i].deg);
	}
	return result;
}

polynomial_t add_polynomial(polynomial_t pol1, polynomial_t pol2) {	
	polynomial_t pol = new_polynomial();
	for(int i=0 ; i<=LIMIT_OF_DEGREE ; i++) {
		pol[i].coef = pol1[i].coef + pol2[i].coef;
	}
	return pol;
}


polynomial_t subtract_polynomial(polynomial_t pol1, polynomial_t pol2) {
	polynomial_t neg_pol2 = new_polynomial();
	for(int i=0 ; i<=LIMIT_OF_DEGREE ; i++) {
		neg_pol2[i].coef = (-1) * pol2[i].coef;
	}

	polynomial_t res_pol = add_polynomial(pol1, neg_pol2);
	free(neg_pol2);
	
	return res_pol;
}

void print_polynomial(polynomial_t pol, char* name) {
	printf("%s\n", name);

	for(int i=LIMIT_OF_DEGREE ; i>=0 ; i--) {
		if(pol[i].coef == 0) {
			continue;
		} else if(pol[i].coef > 0) {
			printf("+%2.1fx^%d ", pol[i].coef, pol[i].deg);
		} else {
			printf("%2.1fx^%d ", pol[i].coef, pol[i].deg);
		}
	}

	printf("\n");
}



/*
struct term_t {
        float coef;
        int deg;
};

typedef term_t* polynomial_t;
typedef struct term_t term_t;

polynomial_t* new_polynomial();

double fval_polynomial(polynomial_t* pol, int x);

polynomial_t* add_polynomial(polynomial_t* pol1, polynomial_t* pol2);
polynomial_t* subtract_polynomial(polynomial_t* pol1, polynomial_t* pol2);

void print_term(void*

*/
