
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

//function that initialize matrix and allocate random value into matrix;
matrix_t matrix_init(int r, int c) {
	matrix_t m = (matrix_t)malloc(sizeof(float*)*r);
	for(int i=0 ; i<r ; i++) {
		m[i] = (float*)malloc(sizeof(float)*c);
	}
	
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			m[i][j] = 0;
		}
	}

	return m;
}
void matrix_alloc(matrix_t m, int r, int c) {
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			m[i][j] = random_value(10);
		}
	}
}

//elementwise matrix operation functions
matrix_t matrix_plus(matrix_t a, matrix_t b, int r, int c) {
	return matrix_operation(a, b, r,c, plus);
}
matrix_t matrix_subtract(matrix_t a, matrix_t b, int r, int c) {
	return matrix_operation(a, b, r, c, subtract);
}
matrix_t matrix_elementwise_multiply(matrix_t a, matrix_t b, int r, int c) {
	return matrix_operation(a, b, r, c, multiply);
}
matrix_t matrix_elementwise_devide(matrix_t a, matrix_t b, int r, int c) {
	return matrix_operation(a, b, r, c, devide);
}

//matrix multiplication function
matrix_t matrix_multiply(matrix_t a, matrix_t b, int r, int c, int n) {
	matrix_t m;
	m = matrix_init(r, n);
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<n ; j++) {
			for(int k=0 ; k<c ; k++) {
				m[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return m;
}

//called by elementwise matrix operation functions
//implementing functional programming
matrix_t matrix_operation(matrix_t a, matrix_t b, int r, int c, float(*func)(float, float)) {
	matrix_t m;
	m = matrix_init(r, c);
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			m[i][j] = (*func)(a[i][j], b[i][j]);
		}
	}
	return m;
}

//arithmethic operation function
float plus(float i, float j) {return i+j;}
float subtract(float i, float j) {return i-j;}
float multiply(float i, float j) {return i*j;}
float devide(float i, float j) {return i/j;}

//allocating random value into matrix
float random_value(int limit) {
	return ((rand()+11) % limit) + 1;
}

//free dynamic data
void free_matrix(matrix_t m, int r, int c) {
	for(int i=0 ; i<r ; i++) {
		free(m[i]);
	}
	free(m);
}

//transpose			
matrix_t transpose(matrix_t a, int r, int c) {
	matrix_t m;
	m = matrix_init(c, r);
	for(int i=0 ; i<c ; i++) {
		for(int j=0 ; j<r ; j++) {
			m[i][j] = a[j][i];
		}
	}
	return m;
}

//sparse
matrix_t convert_sparse(matrix_t m, int r, int c) {
	int nonZero = 0;
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			if(m[i][j] != 0) {nonZero++;}
		}
	}

	matrix_t sm;
	sm = matrix_init(nonZero+1, 3);

	nonZero = 1;
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			if(m[i][j] != 0) {
				sm[nonZero][0] = m[i][j];
				sm[nonZero][1] = i;
				sm[nonZero][2] = j;
				nonZero++;
			}
		}
	}
	sm[0][0] = nonZero - 1;
	sm[0][1] = r;
	sm[0][2] = c;

	return sm;
}	


/*sss*/


