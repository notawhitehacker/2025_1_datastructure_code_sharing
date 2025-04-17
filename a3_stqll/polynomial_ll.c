
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "linkedlist.h"
#include "polynomial_ll.h"

//polynomial_ll extends inkedlist...

polynomial_t* new_polynomial() {
	polynomial_t* pol = (polynomial_t*)malloc(sizeof(polynomial_t));
	*pol = *new_linked_list(compare_term, print_term);
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
    // 새로운 다항식 생성
    polynomial_t* res_pol = new_polynomial();
    node_t *n1, *n2;
    term_t *t1, *t2, *new_t;

    // duplicate and add pol1's terms to res_pol
    n1 = pol1->head;
    while (n1 != NULL) {
        t1 = (term_t*)n1->element;
        new_t = (term_t*)malloc(sizeof(term_t));
        new_t->deg = t1->deg;
        new_t->coef = t1->coef;
        add_node(res_pol, new_node(new_t));
        n1 = n1->next;
    }

    // duplicate and add pol2's terms to res_pol
    n2 = pol2->head;
    while (n2 != NULL) {
        t2 = (term_t*)n2->element;
        new_t = (term_t*)malloc(sizeof(term_t));
        new_t->deg = t2->deg;
        new_t->coef = t2->coef;
        add_node(res_pol, new_node(new_t));
        n2 = n2->next;
    }

    // align the polynomial
    align_polynomial(res_pol);

    return res_pol;
}

polynomial_t* subtract_polynomial(polynomial_t* pol1, polynomial_t* pol2) {
	polynomial_t* neg_pol2 = new_polynomial();
	node_t *n2; term_t *t2;
	term_t *ng_t2;
	
	//negate pol2's terms and duplicate to neg_pol2
	n2 = pol2->head;
	while(n2 != NULL) {
		ng_t2 = (term_t*)malloc(sizeof(term_t));
		t2 = (term_t*)n2->element;
		ng_t2->deg = t2->deg;
		ng_t2->coef = (-1) * t2->coef;
		n2 = n2->next;
		add_node(neg_pol2, new_node(ng_t2));
	}

	polynomial_t* res_pol = add_polynomial(pol1, neg_pol2);
	
	make_linked_list_empty(neg_pol2);
	free(neg_pol2);
	
	return res_pol;
}

void align_polynomial(polynomial_t* pol) {
    if(pol->head == NULL) { return; }
    node_t *n, *m, *tmpnode;
    term_t *now, *next, *tmp;

    n = pol->head;
    while(n->next != NULL) {
        n = n->next;
    }

    // bubblesort by degree
    for(; n->prev != NULL ; n = n->prev) {
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
			delete_node(pol, n->next);
			n = pol->head;
			continue;
		}
		n = n->next;
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

int compare_term(void* n1, void* n2) {
	term_t *t1, *t2;
	t1 = ((term_t*)((node_t*)n1)->element);
	t2 = ((term_t*)((node_t*)n2)->element);
	if(t1->deg == t2->deg && t1->coef == t2->coef) {
		return 1;
	} else return 0;
}
