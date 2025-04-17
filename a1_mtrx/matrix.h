
#ifndef MATRIX_H
#define MATRIX_H

typedef float** matrix_t;
//typedef matrix_t sparse_matrix_t;

matrix_t matrix_init(int, int);
void matrix_alloc(matrix_t, int, int);
	
matrix_t matrix_plus(matrix_t, matrix_t, int, int);
matrix_t matrix_subtract(matrix_t, matrix_t, int, int);
matrix_t matrix_elementwise_multiply(matrix_t, matrix_t, int, int);
matrix_t matrix_elementwise_devide(matrix_t, matrix_t, int, int);

matrix_t matrix_multiply(matrix_t, matrix_t, int, int, int);

matrix_t matrix_operation(matrix_t, matrix_t, int, int, float(*)(float, float));

float plus(float, float);
float subtract(float, float);
float multiply(float, float);
float devide(float, float);

float random_value(int);

void free_matrix(matrix_t, int, int); 

matrix_t transpose(matrix_t, int, int);
matrix_t convert_sparse(matrix_t, int, int);

#endif

