#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes an identity matrix.
 */
void init_identity_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Multiply a matrix by a real value.
 */
void mult_scalar_matrix(float result[3][3], float scalar, const float matrix[3][3]);

/**
 * Multiply a matrix by another matrix.
 */
void multiply_matrices(float result[3][3], const float matrix_a[3][3], const float matrix_b[3][3]);


/**
 * Transform a point by a matrix.
 */
void transform_point(float result[3], const float matrix[3][3], const float p[3]);

/**
 * Print the elements of the point.
 */
void print_point(const float point[3]);

/**
 * Initializes a point with Descartes.
 */
void init_point(float result[3], const float x, const float y);

/**
 * Initializes a shifted matrix.
 */
void init_shift_matrix(float matrix[3][3], const float p[3]);

/**
 * Initializes a rotated matrix.
 */
void init_rotate_matrix(float matrix[3][3], const float angle);

/**
 * Initializes a scaled matrix.
 */
void init_scale_matrix(float matrix[3][3], const float scale);

#endif // MATRIX_H

