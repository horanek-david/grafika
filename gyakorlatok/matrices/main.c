#include "matrix.h"

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
    print_matrix(b);
    
    add_matrices(a, b, c);

    print_matrix(c);
	
	// Initializes an identity matrix
	init_identity_matrix(a);
	printf("Identity matrix:\n");
	print_matrix(a);
	
	// Multiply a matrix by a real value.
	mult_scalar_matrix(b, 1000, a);
	printf("Multiply by scalar:\n");
	print_matrix(b);
	
	// Multiply a matrix by another matrix.
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
	init_zero_matrix(g);
	
	multiply_matrices(g, e, f);
	printf("Matrix * matrix:\n");
	print_matrix(g);


	// Transform a point by a matrix
	
	//float p[3] = {1.0f,2.0f,1.0f};
	float p[3];
	init_point(p, 1.0f, 2.0f);
	
	float t[3] = {0.0f,0.0f,0.0f};
	
	transform_point(t, e, p);
	printf("Matrix * point:\n");
	print_point(t);
	printf("\n");
	
	//Shift a point
	
	init_identity_matrix(a);
	//printf("Identity matrix:\n");
	//print_matrix(a);
	
	float h[3] = {0.0f,5.0f,1.0f}; //The base point
	float s[3] = {0.0f,3.0f,0.0f}; //I want to shift the base point with this point
	
	printf("Print out a shifted point:\n\nOld point:\n");
	print_point(h);
	
	init_shift_matrix(a, s);
	//print_matrix(a);
	//printf("\n");
	
	float r[3] = {0.0f,0.0f,0.0f};
	transform_point(r, a, h); 
	printf("New point:\n");
	print_point(r);
	printf("\n");
	
	// Rotate a point
	init_identity_matrix(a);
	float l[3] = {4.0f,0.0f,1.0f}; //The base point
	float angle = 90.0f;  //I want to rotate the point with this angle
	
	printf("Print out a rotated point with%4.0f:\n\nOld point:\n", angle);
	print_point(l);
	
	init_rotate_matrix(a, angle);
	
	float k[3] = {0.0f,0.0f,0.0f};
	transform_point(k, a, l);
	
	printf("New point:\n");
	print_point(k);
	printf("\n");
	
	// Scale a point
	init_identity_matrix(a);
	float j[3] = {4.0f,0.0f,1.0f};
	float scale = 1.5f;
	
	printf("Print out a scaled point with%4.1f:\n\nOld point:\n", scale);
	print_point(j);
	
	init_scale_matrix(a, scale);
	
	float o[3] = {0.0f,0.0f,0.0f};
	transform_point(o, a, j);
	
	printf("New point:\n");
	print_point(o);
	printf("\n");
	
	
	return 0;
}

