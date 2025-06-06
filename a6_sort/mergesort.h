
#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdlib.h>

#include "array.h"

void merge_sort(array_t arr, size_t size);
void swt_ms(array_t arr1, array_t arr2, index p, index r);
void swt_merge(array_t arr1, array_t arr2, index p, index q, index r);

#endif
