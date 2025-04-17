
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linkedlist.h"
#include "polynomial_ll.h"

//polynomial_ll extends inkedlist...

polynomial_t* new_polynomial() {
	polynomial_t* pol = (polynomial_t*)malloc(sizeof(polynomial_t));
	*pol = *new_linked_list(compare_by_degree, print_term);
	return pol;
}

double fval_polynomial(polynomial_t* pol, int x) {
	if(pol->head == NULL) { return 0;}
	node_t* n; term_t* t; double result = 0;
	
	n = pol->head;
	while(n != NULL) {
		t = (term_t*)n->element;
		result += t->coef * pow(x, t->deg);
		n = n->next;
	}
	return result;
}

polynomial_t* add_polynomial(polynomial_t* pol1, polynomial_t* pol2) {
	polynomial_t* res_pol = new_polynomial();
	node_t *n1, *n2;
	term_t *t1, *t2, *new_t;

	n1 = pol1->head; n2 = pol2->head;
	//merge two polynomial
	while(n1 != NULL && n2 != NULL) {
		t1 = (term_t*)n1->element;
		t2 = (term_t*)n2->element;
		new_t = (term_t*)malloc(sizeof(term_t));
		if(t1->deg == t2->deg) {
			new_t->deg = t1->deg;
			new_t->coef = t1->coef + t2->coef;
			n1 = n1->next; n2 = n2->next;
		} else if(t1->deg > t2->deg) {
			new_t->deg = t1->deg;
			new_t->coef = t1->coef;
			n1 = n1->next;
		} else {
			new_t->deg = t2->deg;
			new_t->coef = t2->coef;
			n2 = n2->next;
		}
		add_node(res_pol, new_node(new_t));
		printf("add node(deg=%d, coef=%f)\n", new_t->deg, new_t->coef);
	}

	while(n1 != NULL) {
		t1 = (term_t*)n1->element;
		new_t = (term_t*)malloc(sizeof(term_t));
		new_t->deg = t1->deg;
		new_t->coef = t1->coef;
		n1 = n1->next;
		add_node(res_pol, new_node(new_t));
		printf("add node(deg=%d, coef=%f)\n", new_t->deg, new_t->coef);
	} 
	while(n2 != NULL) {
		t2 = (term_t*)n2->element;
		new_t = (term_t*)malloc(sizeof(term_t));
		new_t->deg = t2->deg;
		new_t->coef = t2->coef;
		n2 = n2->next;
		add_node(res_pol, new_node(new_t));
		printf("add node(deg=%d, coef=%f)\n", new_t->deg, new_t->coef);
	}
		printf("add operation finished\n");	
	return res_pol;
}

polynomial_t* subtract_polynomial(polynomial_t* pol1, polynomial_t* pol2) {
	polynomial_t* neg_pol2 = new_polynomial();
	node_t *n2; term_t *t2;
	term_t *ng_t2;
	
	n2 = pol2->head;
	while(n2->next != NULL) {
		n2 = n2->next;
	}

	while(n2->prev != NULL) {
		ng_t2 = (term_t*)malloc(sizeof(term_t));
		t2 = (term_t*)n2->element;
		ng_t2->deg = t2->deg;
		ng_t2->coef = (-1) * t2->coef;
		n2 = n2->prev;
		add_node(neg_pol2, new_node(ng_t2));
	}

	polynomial_t* res_pol = add_polynomial(pol1, neg_pol2);
	
	make_linked_list_empty(neg_pol2);
	free(neg_pol2);
	
	return res_pol;
}

void align_polynomial(polynomial_t* pol) {
    if(pol->head == NULL) { return; }

    node_t *n, *m;
    term_t *now, *next, *tmp;
    n = pol->head;
    while(n->next != NULL) {
        n = n->next;
    }

    // bubblesort by degree
    for(; n->prev != pol->head ; n = n->prev) {
        for(m = pol->head ; m != n ; m = m->next) {
            now = (term_t*)m->element;
            next = (term_t*)m->next->element;
            if(now->deg < next->deg) {
                tmp = m->element;
                m->element = m->next->element;
                m->next->element = tmp;
            }
        }
    }

    // combining equal degree terms into one
    n = pol->head;
    while(n != NULL && n->next != NULL) {
        now = (term_t*)n->element;
        next = (term_t*)n->next->element;
        if(now->deg == next->deg) {
            now->coef += next->coef;
            delete_node(pol, next);
            n = n->prev;
        } else {
            n = n->next;
        }
    }
}

void print_term(void* t) {
	term_t* g = (term_t*)t;
	if(g->deg != 0) {
		if(g->coef > 0) {
			printf("+%2.1fx^%d ", g->coef, g->deg);
		} else if(g->coef < 0) {
			printf("%2.1fx^%d ", g->coef, g->deg);
		}
	} else {
		if(g->coef > 0) {
			printf("+%2.1f ", g->coef);
		} else if(g->coef < 0) {
			printf("%2.1f ", g->coef);
		}
	}
}

int compare_by_degree(void* t1, void* t2) {
	if( ((term_t*)((node_t*)t1)->element)->deg
			> ((term_t*)((node_t*)t2)->element)->deg ) {
		return 1;
	} else return 0;
}
