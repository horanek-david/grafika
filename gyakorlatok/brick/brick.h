#ifndef BRICK_H
#define BRICK_H

/**
 * Data of a brick object in Descartes coordinate system
 */
typedef struct Brick
{
	double x;
	double y;
	double z;
} Brick;
	
/**
 * Set the size of the brick
 */
double set_brick_size(Brick* brick, double x, double y, double z);

/**
 * Calculate the volume of the brick.
 */
double calc_brick_volume(const Brick* brick);

/**
 * Calculate the surface of the brick.
 */
double calc_brick_surface(const Brick* brick);

/**
 * Examine if it is a cube
 */
int is_cube(const Brick* brick);

#endif // BRICK_H