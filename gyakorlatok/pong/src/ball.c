#include "ball.h"

void move_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
}

void start_ball(Ball* ball, float x, float y)
{
    ball->radius = 50;
    move_ball(ball, x, y);
    ball->speed_x = 100;
    ball->speed_y = 100;
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

void set_radius_ball(Ball* ball, float radius, float limit_min, float limit_max){
	
	if (radius < limit_min) {
        ball->radius = limit_min;
    } else if (radius > limit_max) {
        ball->radius = limit_max;
    }else{
		ball->radius = radius;
	}
}

