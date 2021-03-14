#include "scene.h"
#include <GL/glut.h>
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
	scene->rotate_speed = 0.0;
	scene->position.x = 0.0;
	scene->position.y = 0.0;
	scene->position.z = 0.0;
	scene->position_speed.x = 0.0;
	scene->position_speed.y = 0.0;
	scene->position_speed.z = 0.0;


	load_model(&(scene->cube_model), "models/cube.obj");
	load_model(&(scene->house_model), "models/house.obj");
	load_model(&(scene->kocka_model), "models/kocka.obj");

	print_model_info(&(scene->cube_model));
	print_bounding_box(&(scene->cube_model));
}

void update_scene(Scene* scene, double time)
{
	scene->rotate_speed += time * 10.0;
	scene->position.x += scene->position_speed.x * time;
	scene->position.y += scene->position_speed.y * time;
	scene->position.z += scene->position_speed.z * time;
}

void set_material_speed(Scene* scene, float speed)
{
	scene->position_speed.x = speed;
}

void set_material_side_speed(Scene* scene, float speed)
{
	scene->position_speed.y = speed;
}

void set_material_lift_speed(Scene* scene, float speed)
{
	scene->position_speed.z = speed;
}


void draw_scene(const Scene* scene)
{
	int i, j;

	draw_origin();

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			glPushMatrix();
			glTranslatef((float)i, (float)j, 0.0);
			glColor3f(0.1 * (float)i, 0.1 * (float)j, 0.1);
			draw_model(&(scene->cube_model));
			glPopMatrix();
		}
	}

	glPushMatrix();
	glTranslatef(-3.0, 0.0, 0.0);
	glColor3f(0.5, 0.1, 0.9);
	glTranslatef(scene->position.x, scene->position.y, scene->position.z);
	draw_model(&(scene->kocka_model));
	glPopMatrix();

	glPushMatrix();
	glScalef(0.03, 0.03, 0.03);
	glTranslatef(0.0, -150.0, -10.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glRotatef(scene->rotate_speed, 0.0, 1.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	draw_model(&(scene->house_model));
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