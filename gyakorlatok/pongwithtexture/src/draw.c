#include "draw.h"
#include "stdlib.h"
#include "GL/glut.h"

#include <obj/load.h>
#include <obj/draw.h>

#define _USE_MATH_DEFINES
#include <math.h>

void init_game(Game* game)
{
    game->pad_texture_id = load_texture("textures/pad.png"); 
	game->ball_texture_id = load_texture("textures/cube.png"); 
	game->bg_texture_id = load_texture("textures/bg.png"); 
}

void draw_background(Game* game)
{
	glBindTexture(GL_TEXTURE_2D, game->bg_texture_id);
	glPushMatrix();
	glBegin(GL_QUADS);
	
	glTexCoord2f(0, 0);
	glVertex3f(1, 1, -3);

	glTexCoord2f(0, 1);
	glVertex3f(1, game->height-1, -3);

	glTexCoord2f(1, 1);
	glVertex3f(game->width-1, game->height-1, -3);

	glTexCoord2f(1, 0);
	glVertex3f(game->width-1, 1, -3);

	glEnd();
	glPopMatrix();
}

void draw_leftpad(Game* game)
{
	float x1, x2, y1, y2;

	x1 = 0;
	x2 = 50;
	y1 = game->left_pad.position;
	y2 = y1 + game->left_pad.size;

	glBindTexture(GL_TEXTURE_2D, game->pad_texture_id);
	
	glPushMatrix();
	glBegin(GL_QUADS);
	
	/* glColor3f(1.0, 0.0, 0.0); */
	glTexCoord2f(0, 0);
	glVertex2f(x1, y1);

	/* glColor3f(0.8, 0.2, 0.0); */
	glTexCoord2f(1, 0);
	glVertex2f(x2, y1);

	/* glColor3f(1.0, 0.4, 0.0); */
	glTexCoord2f(1, 1);
	glVertex2f(x2, y2);

	/* glColor3f(0.9, 0.3, 0.0); */
	glTexCoord2f(0, 1);
	glVertex2f(x1, y2);

	glEnd();
	glPopMatrix();
}

void draw_rightpad(Game* game)
{
	float x1, x2, y1, y2;

	x1 = game->width - 50;
	x2 = game->width;
	y1 = game->right_pad.position;
	y2 = y1 + game->right_pad.size;

	glBindTexture(GL_TEXTURE_2D, game->pad_texture_id);
	glPushMatrix();
	glBegin(GL_QUADS);
	
	/* glColor3f(1.0, 0.0, 0.0); */
	glTexCoord2f(0, 0);
	glVertex2f(x1, y1);

	/* glColor3f(0.8, 0.2, 0.0); */
	glTexCoord2f(1, 0);
	glVertex2f(x2, y1);

	/* glColor3f(1.0, 0.4, 0.0); */
	glTexCoord2f(1, 1);
	glVertex2f(x2, y2);

	/* glColor3f(0.9, 0.3, 0.0); */
	glTexCoord2f(0, 1);
	glVertex2f(x1, y2);

	glEnd();
	glPopMatrix();
}

void draw_ball(Game* game)
{
	float y, x, phi;
	phi = 0.0;

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, game->ball_texture_id);

	glTranslatef(game->ball.x, game->ball.y, 0.0);
	glRotatef(game->ball.rotation, 0.0, 0.0, 1.0); 
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5, 0.5, 0.5);

	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	while(phi < M_PI * 2){
		x = game->ball.radius * cos(phi);
		y = game->ball.radius * sin(phi);
		glTexCoord2f(cos(phi), sin(phi));
		glVertex3f(x, y, 0);
		phi += 0.01;
	}
	glEnd();

	/* glutSolidSphere(game->ball.radius, 8, 8); */
	glPopMatrix();
}

void drawString(Game* game) 
{
	int x, y, width;
	char str[30];
	char* c;

	sprintf(str, "%d - %d", game->left_pad_counter, game->right_pad_counter);
	
	width = glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, str);
	x = ((game->width - width) / 2) - 10;
	y = 50;

	glPushMatrix();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_COLOR_MATERIAL);
		glTranslated((float)x, (float)y, 0);
		
		glBegin(GL_QUADS);
			glColor3f(0.8, 0.2, 0.6);
			glVertex3f(-10.0, 5.0, 0.0);
			glVertex3f(60.0, 5.0, 0.0);
			glVertex3f(60.0, -20.0, 0.0);
			glVertex3f(-10.0, -20.0, 0.0);
		glEnd();

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glColor3f(1, 0.5, 0.3);
	glRasterPos2f(x, y);

	for (c = str; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  
	}
}

void draw_game(Game* game)
{
	/* Background */
	draw_background(game);

	/* Left pad */
	draw_leftpad(game);

	/* Right pad */
	draw_rightpad(game);
	
	/* Ball */
	draw_ball(game);

	/* Score */
	drawString(game);	

}

