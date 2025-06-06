
#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

//initializer
node_t* new_node(void* e) {
	node_t* n = (node_t*)malloc(sizeof(node_t));
	n->element = e;
	n->prev = NULL; n->next = NULL;
	return n;
}
linked_list_t* new_linked_list(
		int(*compare)(void*, void*),
		void(*print_element)(void*)) {
	linked_list_t* l = (linked_list_t*)malloc(sizeof(linked_list_t));
	l->head = NULL;
	l->compare = compare;
	l->print_element = print_element;
	return l;
}

int is_empty(linked_list_t* l) {
	if(l->head == NULL) {
		return 1;
	}
	return 0;
}

void print_linked_list(linked_list_t* l, char* name) {
	node_t* n = l->head;
	printf("%s\n",name);
	while(n != NULL) {
		l->print_element(n->element);
		n = n->next;
	}
	printf("\n");
}

void add_node(linked_list_t* l, node_t* n) {
	n->next = l->head;
	n->prev = NULL;
	if(l->head != NULL) {
		l->head->prev = n;
	}
	l->head = n;
}

node_t* find_node(linked_list_t* l, void* e){
	node_t* n = l->head;
	while(n != NULL) {
		if(l->compare(n, e)) {
			break;
		}
		n = n->next;
	}
	return n;
}

void delete_node(linked_list_t* l, void* e) {
	node_t* n = find_node(l, e);
	if(n == NULL) {
		return;
	}
	if(n->prev != NULL) {
		n->prev->next = n->next;
	} else {
		l->head = n->next;
	}
	if(n->next != NULL) {
		n->next->prev = n->prev;
	}
	free(n);
}

void make_linked_list_empty(linked_list_t* l) {
	node_t* n = l->head;
	node_t* nxt;
	while(n != NULL) {
		nxt = n->next;
		free(n);
		n = nxt;
	}
	l->head = NULL;
}
