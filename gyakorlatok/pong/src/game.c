#include "game.h"

void resize_game(Game* game, int width, int height)
{
	game->width = width;
	game->height = height;
	game->left_pad.size = 200;
	game->right_pad.size = 200;
	restart_game(game);
}

void restart_game(Game* game)
{
	float center_x;
	float center_y;

	center_x = game->width / 2;
	center_y = game->height / 2;

	move_pad(&(game->left_pad), center_y, game->height);
	move_pad(&(game->right_pad), center_y, game->height);
	start_ball(&(game->ball), center_x, center_y);
}

void update_game(Game* game, double time)
{
	if(game->ball.rotation > 360){
		game->ball.rotation = 0;
	}

	update_ball(&(game->ball), time);

	/* Changed that the ball can only bounce back when it's hit one of the pads else it goes out. */
	if (game->ball.x - game->ball.radius < 50 && (game->ball.y + game->ball.radius >= game->left_pad.position && game->ball.y - game->ball.radius <= game->left_pad.position + game->left_pad.size)) {
		game->ball.x = game->ball.radius + 50;
		game->ball.speed_x *= -0.8;
		game->ball.speed_y *= 0.8; /* */

		set_radius_ball(&(game->ball), game->ball.radius-5, 10, 100);
	}

	if (game->ball.x - game->ball.radius < -(2 * game->ball.radius)){
		game->right_pad_counter += 1;

		float center_x;
		float center_y;

		center_x = game->width / 2;
		center_y = game->height / 2;
		start_ball(&(game->ball), center_x, center_y);
	}




	/* Changed that the ball can only bounce back when it's hit one of the pads else it goes out. */
	if (game->ball.x + game->ball.radius > game->width - 50 && (game->ball.y + game->ball.radius >= game->right_pad.position && game->ball.y - game->ball.radius <= game->right_pad.position + game->right_pad.size)) {
		game->ball.x = game->width - game->ball.radius - 50;
		game->ball.speed_x *= -0.8;
		game->ball.speed_y *= 0.8;

		set_radius_ball(&(game->ball), game->ball.radius-5, 10, 100);
	}

	if (game->ball.x + game->ball.radius > game->width + (2 * game->ball.radius) ){
		game->left_pad_counter += 1;

		float center_x;
		float center_y;

		center_x = game->width / 2;
		center_y = game->height / 2;
		start_ball(&(game->ball), center_x, center_y);
	}

	if (game->ball.y - game->ball.radius < 0) {
		game->ball.y = game->ball.radius;
		game->ball.speed_y *= -1.3;
		game->ball.speed_x *= 1.3; 
	}

	if (game->ball.y + game->ball.radius > game->height) {
		game->ball.y = game->height - game->ball.radius;
		game->ball.speed_y *= -1.3;
		game->ball.speed_x *= 1.3;	/* */
	}

}

void move_left_pad(Game* game, float position)
{
	move_pad(&(game->left_pad), position, game->height);
}

void move_right_pad(Game* game, float position)
{
	move_pad(&(game->right_pad), position, game->height);
}

void click_ball(Game* game, int x, int y)
{
	move_ball(&(game->ball), x, y);
}

void set_radius(Game* game, float radius, float limit_min, float limit_max)
{
	set_radius_ball(&(game->ball), radius, limit_min, limit_max);
}