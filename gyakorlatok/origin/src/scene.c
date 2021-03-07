#include "scene.h"

#include <GL/glut.h>

#include <math.h>

void init_scene(Scene* scene)
{
	scene->teapot_rotation = 0.0;
	scene->sphere_rotation = 0.0;
}

void update_scene(Scene* scene, double time)
{
	scene->teapot_rotation += 10.0 * time;
	scene->sphere_rotation += 10.0 * time;
}

void update_old(Scene* scene, int old_x, int old_y)
{
	scene->old_x = old_x;	
	scene->old_y = old_y;	
}

void draw_scene(const Scene* scene)
{
	int i;
	
    draw_origin();
	draw_triangle();
	draw_sphere(scene);
	draw_chess();
	
	glPushMatrix();
	glTranslatef(1.5, 1.0, 0.0);
	draw_pyramid();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(1.5, -1.0, 0.0);
	draw_cylinder();
	glPopMatrix();
	
	
	/*
	glPushMatrix();
	for (i=0; i<10; i++){
		draw_cylinder();
		glScalef(1, 1, 1.5);
		glTranslatef(0, 1, 0);
	}
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 2);
	glRotatef(scene->teapot_rotation, 0, 1, 0);
	glutWireTeapot(1);
	glPopMatrix();
	
	
	glBegin(GL_TRIANGLES);

    
	glColor3f(1, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 1);
	
	
    glEnd();
	*/
}

void draw_cylinder()
{
	float x, y, phi, h, radius;

	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);

	radius = 0.3;
	phi=0.0;
	h = 0.8;

	glColor3f(0.0, 0.0, 1.0);
	while(phi < M_PI * 2){
		x = radius * cos(phi);
		y = radius * sin(phi);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, h);
		phi += 0.0001;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	phi = 0.0;

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	while(phi < M_PI * 2){
		x = radius * cos(phi);
		y = radius * sin(phi);
		glVertex3f(x, y, 0);
		phi += 0.0001;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	phi = 0.0;

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, h);
	while(phi < M_PI * 2){
		x = radius * cos(phi);
		y = radius * sin(phi);
		glVertex3f(x, y, h);
		phi += 0.0001;
	}
	glEnd();
	glPopMatrix();
}

void draw_origin()
{
	glBegin(GL_LINES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1);

	glEnd();
}

void draw_triangle()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);

	glColor3f(1 , 1, 0);
	glVertex3f(1, 0, 0);

	glColor3f(0 , 1, 1);
	glVertex3f(0, 1, 0);

	glColor3f(1 , 0, 1);
	glVertex3f(0, 0, 1);

	glEnd();
	glPopMatrix();
}

void draw_sphere(Scene* scene)
{
	glPushMatrix();
	glRotatef(scene->sphere_rotation * 2.0, 0.0, 0.0, 1.0);
	glColor3f(0.69, 0.6762, 0.6891);
	glTranslatef(0.5, 0.5, 0.5);
	glRotatef(scene->sphere_rotation, 0.0, 0.0, 1.0);
	glutSolidSphere(0.2, 10.0, 10.0);
	glColor3f(0.1, 0.1, 0.1);
	glutWireSphere(0.2, 10.0, 10.0);
	glPopMatrix();
}

void draw_pyramid()
{
	float x, y, phi, h, radius;

	radius = 0.3;
	phi = 0.0;
	h = 0.5;

	glPushMatrix();
	/*Pyramid cloak*/
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0, 0.0, h);

	while(phi < M_PI * 2){
		x = radius * cos(phi);
		y = radius * sin(phi);
		glColor3f(0.1, 1.0, 0.0);
		glVertex3f(x, y, 0.0);
		phi += 0.01;
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	phi = 0.0;
	glVertex3f(0.0, 0.0, 0.0);

	while(phi < M_PI * 2){
		x = radius * cos(phi);
		y = radius * sin(phi);
		glColor3f(0.1, 1.0, 0.0);
		glVertex3f(x, y, 0.0);
		phi += 0.01;
	}
	glEnd();

	glPopMatrix();
}

void draw_chess()
{
	float y, x, s;
	int i, j, black, white;

	s = (float)1 / 8;
	x = 0.0;
	y = 0.0;
	black = 1;

	glPushMatrix();
	for(i=0;i<8;i++){
		if(i%2 == 0){
			black = 1;
		}else{
			black = 0;
		}

		for(j=0;j<8;j++){
			glBegin(GL_POLYGON);
			if(black == 1){
				glColor3f(0.2, 0.2, 0.2);
				black = 0;
			}else{
				glColor3f(1.0, 1.0, 1.0);
				black = 1;
			}

			glVertex3f(x, y, 0.0);
			glVertex3f(x + s, y, 0.0);
			glVertex3f(x + s, y + s, 0.0);
			glVertex3f(x, y + s, 0.0);
			glEnd();

			x += s;
		}

		y += s;
		x = 0;
	}
	glPopMatrix();
}