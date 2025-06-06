
#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"
#include "array.h"

void merge_sort(array_t arr, size_t size) {
	array_t arr2 = array_init(size);
	for(int i=0 ; i<size ; i++) {
		arr2[i] = arr[i];
	}
	swt_ms(arr, arr2, 0, size-1);
	free(arr2);
}

void swt_ms(array_t arr1, array_t arr2, int p, int r) {
	if(p<r) {
		int q = (int)(r+p)/2;
		swt_ms(arr2, arr1, p, q);
		swt_ms(arr2, arr1, q+1, r);
		swt_merge(arr1, arr2, p ,q ,r);
	}
}

void swt_merge(array_t arr1, array_t arr2, int p, int q, int r) {
	int l1 = q, l2 = r;//last index of sublist
	int x1 = p, x2 = q+1;//current or first index of sublist
	int j = p;

	while(x1<=l1 && x2<=l2) {
		if(arr2[x1] > arr2[x2]) {
			arr1[j++] = arr2[x2++];
		} else {
			arr1[j++] = arr2[x1++];
		}
	}

	if(x2<=l2) {
		for(int i=x2 ; i<=l2 ;) {
			arr1[j++] = arr2[i++];
		}
	} else {
		for(int i=x1 ; i<=l1 ;) {
			arr1[j++] = arr2[i++];
		}
	}
}







