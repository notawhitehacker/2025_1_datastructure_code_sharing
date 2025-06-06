
#ifndef HEAP_H
#define HEAP_H

#include "array.h"

//indexing macro
#define parent(index) (int)((index+1)/2-1) // floor(i/2)
#define left(index) 2*(index+1)-1
#define right(index) 2*(index+1)

//definition of heap
typedef struct {
	array_t list;
	int top;
} heap_t;

heap_t* heap_init(size_t size);

void build_max_heap(heap_t* h);
void max_heapify(heap_t* h, index k);
void heap_sort(heap_t* h);

void print_heap(heap_t* h, size_t size);

void delete_heap(heap_t* h);

#endif
