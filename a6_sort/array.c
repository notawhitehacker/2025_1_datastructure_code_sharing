
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

array_t array_init(size_t size) {
	array_t arr;
	arr = (array_t)malloc(sizeof(int)*size);

	for(int i=0 ; i<size ; i++) {
		arr[i] = random_int_val();
	}
	return arr;
}

void print_array(array_t arr, size_t size, char* name) {
	printf("%s\n",name);
	for(int i=0 ; i<size ; i++) {
		printf("%d: %d\n",i,arr[i]);
	}
}

int random_int_val() {
        int v=0;
        for(int cnt=0 ; cnt<7 ; cnt++) {
                v += (rand()+1) % 10;
                v *= 10;
        }
        return v/10;
}
