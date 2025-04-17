

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "polynomial_ll.h"

int main() {
	printf("1");
	polynomial_t* pol1 = new_polynomial();
	polynomial_t* pol2 = new_polynomial();
	polynomial_t* pol3 = new_polynomial();

	printf("2");
	term_t** tlist1 = (term_t**)malloc(sizeof(term_t*)*5);
	term_t** tlist2 = (term_t**)malloc(sizeof(term_t*)*5);
	term_t** tlist3 = (term_t**)malloc(sizeof(term_t*)*5);

	for(int i=0 ; i<5 ; i++) {
		tlist1[i] = (term_t*)malloc(sizeof(term_t));
		tlist2[i] = (term_t*)malloc(sizeof(term_t));
		tlist3[i] = (term_t*)malloc(sizeof(term_t));
	}

	printf("3");
	tlist1[0]->deg = 4; tlist1[0]->coef = 6.7;
	tlist1[1]->deg = 3; tlist1[1]->coef = 3.2;
	tlist1[2]->deg = 2; tlist1[2]->coef = -1;
	tlist1[3]->deg = 1; tlist1[3]->coef = 1;
	tlist1[4]->deg = 0; tlist1[4]->coef = -2;

	printf("4");
	tlist2[0]->deg = 6; tlist2[0]->coef = 0.8;
	tlist2[1]->deg = 5; tlist2[1]->coef = -3;
	tlist2[2]->deg = 4; tlist2[2]->coef = 6.7;
	tlist2[3]->deg = 1; tlist2[3]->coef = 5;
	tlist2[4]->deg = 0; tlist2[4]->coef = 2;

	printf("5");
	tlist3[0]->deg = 3; tlist3[0]->coef = -5;
	tlist3[1]->deg = 6; tlist3[1]->coef = -3;
	tlist3[2]->deg = 2; tlist3[2]->coef = 6.7;
	tlist3[3]->deg = 3; tlist3[3]->coef = 5;
	tlist3[4]->deg = 2; tlist3[4]->coef = 2;

	printf("6");
	for(int i=0 ; i<5 ; i++) {
		add_node(pol1, new_node(tlist1[4-i]));
		add_node(pol2, new_node(tlist2[4-i]));
		add_node(pol3, new_node(tlist3[4-i]));
	}

	print("7");
	print_linked_list(pol1, "pol1");
	print_linked_list(pol2, "pol2");
	print_linked_list(pol3, "pol3");

	printf("8");
	printf("pol1(2) = %f\n", fval_polynomial(pol1, 2));
	
	printf("9");
	polynomial_t* sum_p12 = add_polynomial(pol1, pol2);
	polynomial_t* subtract_p12 = subtract_polynomial(pol1, pol2);

	printf("10");
	print_linked_list(sum_p12, "pol1+pol2");
	print_linked_list(subtract_p12, "pol1-pol2");

	printf("11");
	print_linked_list(pol3, "Before align pol3");
	align_polynomial(pol3);
	print_linked_list(pol3, "After align pol3");


	printf("12");
	return 0;

}
