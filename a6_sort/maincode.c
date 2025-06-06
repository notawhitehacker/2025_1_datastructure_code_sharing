
#include "array.h"
#include "quicksort.h"
#include "mergesort.h"
#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	clock_t start, finish;
	int dur[5];
	int avg_duration;

	int size_list[21];
	for(int i=0 ; i<=20; i++) {
		size_list[i] = 50000 * i;
	}

	array_t arr;
	heap_t* h = heap_init(1);
	free(h->list);

	printf("\nQuick Sort\n");
	for(int s=1 ; s<=20 ; s++) {
		for(int i=0; i<5 ; i++) {
			arr = array_init(size_list[s]);
			start = clock();
			quick_sort(arr, 0, size_list[s]-1);
			finish = clock();
			dur[i] = ((finish - start) * 1000) / (CLOCKS_PER_SEC);
			free(arr);
		}
		avg_duration = (dur[0]+dur[1]+dur[2]+dur[3]+dur[4]) / 5;
		printf("(%d, %d)\n", size_list[s], avg_duration);
	}
	

	printf("\nMerge Sort\n");
	for(int s=1 ; s<=20 ; s++) {
		for(int i=0; i<5 ; i++) {
			arr = array_init(size_list[s]);
			start = clock();
			merge_sort(arr, size_list[s]);
			finish = clock();
			dur[i] = ((finish - start) * 1000) / (CLOCKS_PER_SEC);
			free(arr);
		}
		avg_duration = (dur[0]+dur[1]+dur[2]+dur[3]+dur[4]) / 5;
		printf("(%d, %d)\n", size_list[s], avg_duration);
	}

	printf("\nHeap Sort\n");
	for(int s=1 ; s<=20 ; s++) {
		for(int i=0; i<5 ; i++) {
			h->list = array_init(size_list[s]);
			h->top = size_list[s]-1;
			start = clock();
			heap_sort(h);
			finish = clock();
			dur[i] = ((finish - start) * 1000) / (CLOCKS_PER_SEC);
			free(h->list);
		}
		avg_duration = (dur[0]+dur[1]+dur[2]+dur[3]+dur[4]) / 5;
		printf("(%d, %d)\n", size_list[s], avg_duration);
	}

}
