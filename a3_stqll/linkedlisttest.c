
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

typedef struct {
	int x;
	int y;
} point_t;

int compare_point(void* a, void* b) {
	point_t pa, pb;
	pa = *(point_t*)a; pb = *(point_t*)b;
	if(pa.x == pb.x && pa.y == pb.y) {
		return 1;
	}
	else return 0;
}

void print_point(void* a) {
	point_t pa;
	pa = *(point_t*)a;
	printf("(%d, %d) ",pa.x, pa.y);
}

int main() {
	linked_list_t* l = new_linked_list(compare_point, print_point);
	point_t p1, p2, p3;
	p1.x=9; p1.y=5;
	p2.x=4; p2.y=7;
	p3.x=6; p3.y=2;

	node_t *n1, *n2, *n3;
	n1 = new_node(&p1);
	n2 = new_node(&p2);
	n3 = new_node(&p3);

	add_node(l, n1);
	add_node(l, n2);
	print_linked_list(l, "1");
	add_node(l, n3);
	print_linked_list(l, "2");
	
	node_t* nf = find_node(l, n2);
	print_point(nf->element);
	
	delete_node(l, nf);
	print_linked_list(l, "3");

	printf("empty: %d\n", is_empty(l));
	make_linked_list_empty(l);
	printf("empty: %d\n", is_empty(l));
}
