
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node_t {
	void* element;
	struct node_t* prev;
	struct node_t* next;
};
struct linked_list_t {
	struct node_t* head;
	int (*compare)(void*, void*);
	void (*print_element)(void*);
};

typedef struct node_t node_t;
typedef struct linked_list_t linked_list_t;

node_t* new_node(void* e);
linked_list_t* new_linked_list(
		int(*compare)(void*, void*),
		void(*print_element)(void*));

int is_empty(linked_list_t* l);
void print_linked_list(linked_list_t* l, char* name);
void add_node(linked_list_t* l, node_t* n);
node_t* find_node(linked_list_t* l, void* e);
void delete_node(linked_list_t* l, void* e);
void make_linked_list_empty(linked_list_t* l);

#endif
