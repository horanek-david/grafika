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


void draw_scene(const Scene* scene)
{
	int i;
	
    draw_origin();
	draw_triangle();
	draw_sphere(scene);
	
	/*glPushMatrix();
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
	float x, y, phi, h;
	const float MATH_PI = 3.14159265359875;
	
	glPushMatrix();
	glBegin(GL_QUAD_STRIP);

	phi=0.0;
	h = 1.0;
	while(phi < MATH_PI){
		x = cos(phi);
		y = sin(phi);
		glColor3f(phi / MATH_PI, 1.0 - (phi / MATH_PI), 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, h);
		phi += 0.4;
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

	glColor3f(0.9, 0.9, 0.9);
	glTranslatef(0.5, 0.5, 0.5);
	glRotatef(scene->sphere_rotation, 0.0, 0.0, 1.0);
	glutSolidSphere(0.2, 5.0, 5.0);
	glPopMatrix();
}