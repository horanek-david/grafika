#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "pad.h"
#include "texture.h"


/**
 * Game state representation
 */
typedef struct Game
{
    Ball ball;
    Pad left_pad;
    Pad right_pad;
    int width;
    int height;
	int left_pad_counter; /* I*/
	int right_pad_counter; /* I*/
    GLuint pad_texture_id;
    GLuint ball_texture_id;
    GLuint bg_texture_id;
} Game;

/**
 * Resize the game and update positions.
 */
void resize_game(Game* game, int width, int height);

/**
 * Restart the game.
 */
void restart_game(Game* game);

/**
 * Update the state of the game.
 * @param time elapsed time in seconds
 */
void update_game(Game* game, double time);

/**
 * Move the left pad to the given position.
 */
void move_left_pad(Game* game, float position);

/**
 * Move the right pad to the given position.
 */
void move_right_pad(Game* game, float position);

/**
 * Set radius.
 * @param radius ball radius.
 */
void set_radius(Game* game, float radius, float limit_min, float limit_max);



#endif /* GAME_H */
