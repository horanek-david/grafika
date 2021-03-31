#ifndef DRAW_H
#define DRAW_H

#include "game.h"
#include "texture.h"

/**
 * Initialize the game by loading objects.
 */
void init_draw(Game* game);

/**
 * Draw the background.
 */
void draw_background(Game* game);

/**
 * Draw the left pad.
 */
void draw_leftpad(Game* game);

/**
 * Draw the right pad.
 */
void draw_rightpad(Game* game);

/**
 * Draw the ball.
 */
void draw_ball(Game* game);

/**
 *
 */
void drawString(Game* game);

/**
 * Draw the game.
 */
void draw_game(Game* game);



#endif /* DRAW_H */
