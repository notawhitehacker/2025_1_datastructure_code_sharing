
#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

#define exchange(a, b) if(a != b) {a = a+b; b = a-b; a = a-b;}

typedef int index;

typedef int* array_t;

array_t array_init(size_t size);
void print_array(array_t arr, size_t size, char* name);
int random_int_val(); 

#endif
