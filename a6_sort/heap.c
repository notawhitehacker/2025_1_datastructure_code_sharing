
#include <stdlib.h>
#include <stdio.h>

#include "array.h"
#include "heap.h"

heap_t* heap_init(size_t size) {
	heap_t* h;
	h->list = (array_t)malloc(sizeof(int)*(size));
	h->top = size-1;

	for(index i=0 ; i<size ; i++) {
		h->list[i] = random_int_val();
	}
	
	return h;
}

void build_max_heap(heap_t* h) {
	for(index i = parent(h->top) ; i>=0 ; i--) {
		max_heapify(h, i);
	}
}

void max_heapify(heap_t* h, index k) {
	int max = h->list[k];
	int max_index;
	if(h->top >= left(k) && max < h->list[left(k)]) {
		max = h->list[left(k)];
		max_index = left(k);
	}
	if(h->top >= right(k) && max < h->list[right(k)]) {
		max = h->list[right(k)];
		max_index = right(k);
	}
	
	if(max != h->list[k]) {
		exchange(h->list[max_index], h->list[k]);
		max_heapify(h, max_index);
	}
}
	
void heap_sort(heap_t* h) {
	build_max_heap(h);
	for(index i=h->top ; i>=0 ; i--) {
		exchange(h->list[0], h->list[i]);
		h->top--;
		max_heapify(h, 0);
	}
}

void print_heap(heap_t* h, size_t size) {
	for(index i=0 ; i<size ; i++) {
		printf("%d: %d\n",i, h->list[i]);
	}
}

void delete_heap(heap_t* h) {
	free(h->list);
	free(h);
}


