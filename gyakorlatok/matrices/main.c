#include "matrix.h"

void add_matrix(float a[3][3], float b[3][3], float c[3][3])
{
	init_zero_matrix(b);
	b[1][1] =  8.0f;
	b[2][0] = -3.0f;
	b[2][2] =  5.0f;

	print_matrix(a);
	print_matrix(b);
	add_matrices(a, b, c);
	print_matrix(c);
}

// Initializes an identity matrix.
void identity_matrix(float a[3][3])
{
	init_identity_matrix(a);
	printf("Identity matrix:\n");
	print_matrix(a);
}

// Multiply a matrix by a real value.
void scalar_matrix(float a[3][3], float b[3][3])
{
	mult_scalar_matrix(b, 1000, a);
	printf("Multiply by scalar:\n");
	print_matrix(b);
}

// Multiply a matrix by another matrix.
void multiply_matrix(float e[3][3], float f[3][3], float g[3][3])
{
	init_zero_matrix(g);

	multiply_matrices(g, e, f);
	printf("Matrix * matrix:\n");
	print_matrix(g);
}

// Transform a point by a matrix.
void point_transformation(float t[3], float e[3][3], float p[3])
{
	init_point(p, 1.0f, 2.0f);

	transform_point(t, e, p);
	printf("Matrix * point:\n");
	print_point(t);
	printf("\n");
}

//Shift a point.
void shift_point(float r[3], float a[3][3], float h[3], float s[3])
{
	printf("Print out a shifted point:\n\nOld point:\n");
	print_point(h);

	init_shift_matrix(a, s);

	transform_point(r, a, h); 
	printf("New point:\n");
	print_point(r);
	printf("\n");
}

// Rotate a point.
void rotate_matrix(float k[3], float a[3][3], float l[3], float angle)
{
	printf("Print out a rotated point with%4.0f:\n\nOld point:\n", angle);
	print_point(l);

	init_rotate_matrix(a, angle);

	transform_point(k, a, l);

	printf("New point:\n");
	print_point(k);
	printf("\n");
}

// Scale a point.
void scale_matrix(float a[3][3], float scale_x, float scale_y, float o[3], float j[3])
{
	printf("Print out a scaled point with x:%4.1f and y:%4.1f \n\nOld point:\n", scale_x, scale_y);
	print_point(j);

	init_scale_matrix(a, scale_x, scale_y);

	transform_point(o, a, j);

	printf("New point:\n");
	print_point(o);
	printf("\n");
}

int main(int argc, char* argv[])
{
	float a[3][3] = {
		{ 1.0f, -2.0f,  3.0f},
		{ 5.0f, -3.0f,  0.0f},
		{-2.0f,  1.0f, -4.0f}
	};
	float b[3][3];
	float c[3][3];

	// Multiply a matrix by another matrix task.
	float e[3][3] = {
		{ 2.0f, 1.0f,  3.0f},
		{ 1.0f, 2.0f,  2.0f},
		{ 2.0f, 5.0f,  0.0f}
	};
	float f[3][3] = {
		{ 1.0f, 3.0f,  0.0f},
		{ 2.0f, 5.0f,  4.0f},
		{ 2.0f, 1.0f,  0.0f}
	};
	float g[3][3];

	// Transform a point by a matrix task.
	float p[3];
	float t[3] = {0.0f,0.0f,0.0f};

	//Shift a point.
	float h[3] = {0.0f,5.0f,1.0f}; //The base point
	float s[3] = {0.0f,3.0f,0.0f}; //I want to shift the base point with this point
	float r[3] = {0.0f,0.0f,0.0f};

	// Rotate a point task.
	float l[3] = {4.0f,0.0f,1.0f}; //The base point
	float angle = 90.0f;  //I want to rotate the point with this angle
	float k[3] = {0.0f,0.0f,0.0f};

	// Scale a point task.
	float j[3] = {4.0f,0.0f,1.0f};
	float scale_x = 1.5f;
	float scale_y = 1.5f;
	float o[3] = {0.0f,0.0f,0.0f};


	add_matrix(a, b, c);
	identity_matrix(a);
	scalar_matrix(a, b);
	multiply_matrix(e, f, g);
	point_transformation(t, e, p);
	shift_point(r, a, h, s); 
	rotate_matrix(k, a, l, angle);
	scale_matrix(a, scale_x, scale_y, o, j);

	return 0;
}

