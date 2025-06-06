
#include "quicksort.h"
#include "array.h"


void quick_sort(array_t arr, index p, index r) {
	if(p<r) {
		int q = partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

index partition(array_t arr, index p, index r) {
	index i = p-1;
	for(index j=p ; j<r ; j++) {
		if(arr[r]>arr[j]) {
			i++;
			exchange(arr[j], arr[i]);
		}
	}
	i++;
	exchange(arr[r], arr[i]);
	return i;
}
