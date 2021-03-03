#include "matrix.h"
#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			matrix[i][j] = 0.0;
		}
	}
}

void init_identity_matrix(float matrix[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			if(i == j){
				matrix[i][j] = 1.0;
			}else {
				matrix[i][j] = 0.0;
			}
		}
	}
}

void print_matrix(const float matrix[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			printf("%4.4f ", matrix[i][j]);
		}
			printf("\n");
	}
	printf("\n");
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void mult_scalar_matrix(float result[3][3], float scalar, const float matrix[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			result[i][j] = scalar * matrix[i][j]; 
		}
	}	
}

void multiply_matrices(float result[3][3], const float matrix_a[3][3], const float matrix_b[3][3])
{
	int i;
	int j;
	int k;
	float sum;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			sum = 0.0;
			for (k = 0; k < 3; ++k) {
				sum += matrix_a[i][k] * matrix_b[k][j];
			}

			result[i][j] = sum;
		}
	}		
}

void transform_point(float result[3], const float matrix[3][3], const float p[3])
{
	int i;
	int j;
	float sum;

	for ( i = 0; i < 3; ++i) {
		sum = 0.0;
		for ( j = 0; j < 3; ++j) {
			sum += matrix[i][j] * p[j];
		}

		result[i] = sum;
	}
}

void print_point(const float point[3])
{
	int i;

	for (i = 0; i < 3; ++i) {
		printf("%4.4f ", point[i]);
	}
	printf("\n");
}

void init_point(float result[3], const float x, const float y)
{
	result[0] = x;
	result[1] = y;
	result[2] = 1.0;
}

void init_shift_matrix(float matrix[3][3], const float p[3])
{
	init_identity_matrix(matrix);

	matrix[0][2] = p[0];
	matrix[1][2] = p[1];
}

void init_rotate_matrix(float matrix[3][3], const float angle)
{
	init_identity_matrix(matrix);
	float rad = M_PI/180;

	matrix[0][0] = cos(angle * rad);
	matrix[0][1] = -sin(angle * rad);
	matrix[1][0] = sin(angle * rad);
	matrix[1][1] = cos(angle * rad);
}

void init_scale_matrix(float matrix[3][3], const float scale_x, const float scale_y)
{
	init_identity_matrix(matrix);

	matrix[0][0] = scale_x;
	matrix[1][1] = scale_y;
}