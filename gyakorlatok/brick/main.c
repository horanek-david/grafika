#include "brick.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Brick brick;
	double volume;
	double surface;
	int cube;
	
	set_brick_size(&brick, 3, 3, 3);
	volume = calc_brick_volume(&brick);
	surface = calc_brick_surface(&brick);
	cube = is_cube(&brick);
	
	printf("Brick volume: %lf\n", volume);
	printf("Brick surface: %lf\n", surface);
	
	printf("Are there two same side?\n");
	if(cube == 0)
	{
		printf("No\n");	
	}
	else
	{
		printf("Yes\n");	
	}
	
	return 0;
}