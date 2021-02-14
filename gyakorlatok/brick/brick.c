#include "brick.h"

#include <math.h>

double set_brick_size(Brick* brick, double x, double y, double z)
{
	brick->x = x;
	brick->y = y;
	brick->z = z;
}

double calc_brick_volume(const Brick* brick)
{
	double volume = brick->x * brick->y * brick->z;
	return volume;
}

double calc_brick_surface(const Brick* brick)
{
	double surface = 2 * (brick->x * brick->y + brick->y * brick->z + brick->x * brick->z);
	return surface;
}

int is_cube(const Brick* brick)
{
	int result = 0; // The default value is false
	
	if(brick->x == brick->y)
	{
		result = 1; //Changing the value to true
	}
	else if(brick->y == brick->z)
	{
		result = 1;
	}
	else if(brick->x == brick->z)
	{
		result = 1;
	}
	
	return result;
}