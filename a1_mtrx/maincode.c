
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

void print_matrix(matrix_t m, int r, int c, char* name) {

	printf("%s\n",name);
	for(int i=0 ; i<r ; i++) {
		for(int j=0 ; j<c ; j++) {
			printf("%6.2f ",m[i][j]);
		}
		printf("\n");
	}
}

void print_sparse_matrix(matrix_t sm, int n, char* name) {
	printf("%s\n",name);
	for(int i=0 ; i<n+1 ; i++) {
		printf("%02d %02d %6.2f \n",(int)sm[i][1], (int)sm[i][2], sm[i][0]);
	}
}

int main() {
	srand(time(NULL));

	int r=5, c=5;

	matrix_t A, B;
	A = matrix_init(r,c);
	B = matrix_init(r,c);
	matrix_alloc(A,r,c);
	matrix_alloc(B,r,c);

	matrix_t plus_AB = matrix_plus(A,B,r,c);
	matrix_t subtract_AB = matrix_subtract(A,B,r,c);
	matrix_t e_multiply_AB = matrix_elementwise_multiply(A,B,r,c);
	matrix_t devide_AB = matrix_elementwise_devide(A,B,r,c);
	matrix_t multiply_AB = matrix_multiply(A,B,r,r,c);
	matrix_t transpose_A = transpose(A,r,c);
	matrix_t sparse_A = convert_sparse(A,r,c);

	print_matrix(A,r,c,"A");
	print_matrix(B,r,c,"B");
	print_matrix(plus_AB,r,c,"A+B");
	print_matrix(subtract_AB,r,c,"A-B");
	print_matrix(e_multiply_AB,r,c,"A*B(elementwise)");
	print_matrix(devide_AB,r,c,"A/B");
	print_matrix(multiply_AB,r,c,"A*B");
	print_matrix(transpose_A,r,c,"A^T");
	print_sparse_matrix(sparse_A,(int)sparse_A[0][0],"sparseA");

	matrix_t s_sub_AB = convert_sparse(subtract_AB,r,c);
	print_sparse_matrix(s_sub_AB,s_sub_AB[0][0],"s_sub_AB");


	free_matrix(A,r,c);
	free_matrix(B,r,c);
	free_matrix(plus_AB,r,c);
	free_matrix(subtract_AB,r,c);
	free_matrix(e_multiply_AB,r,c);
	free_matrix(devide_AB,r,c);
	free_matrix(multiply_AB,r,c);
	free_matrix(transpose_A,r,c);
	free_matrix(sparse_A,(int)sparse_A[0][0]+1,3);

	free_matrix(s_sub_AB,(int)s_sub_AB[0][0]+1,3);	
	return 0;
}

