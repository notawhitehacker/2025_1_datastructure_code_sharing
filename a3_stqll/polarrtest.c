
#include <stdio.h>

#include "polynomial_arr.h"

int main() {
        polynomial_t pol1 = new_polynomial();
        polynomial_t pol2 = new_polynomial();
	
        pol1[4].coef = 6.7;
	pol1[3].coef = 3.2;
        pol1[2].coef = -1;
        pol1[1].coef = 1;
        pol1[0].coef = -2;

        pol2[4].coef = 0.8;
	pol2[3].coef = -3;
        pol2[2].coef = 6.7;
        pol2[1].coef = 5;
        pol2[0].coef = 2;

	print_polynomial(pol1, "pol1");
	print_polynomial(pol2, "pol2");

	printf("pol1(x) = %f\n", fval_polynomial(pol1, 2));

	polynomial_t sum_pol12 = add_polynomial(pol1, pol2);
	polynomial_t subtract_pol12 = subtract_polynomial(pol1, pol2);

	print_polynomial(sum_pol12, "sum_pol12");
	print_polynomial(subtract_pol12, "subtract_pol12");

}

