#include "callbacks.h"

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0

struct 
{
	int x;
	int y;
} mouse_position;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	set_view(&camera);
	draw_scene(&scene);

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
	int x, y, w, h;
	double ratio;

	ratio = (double)width / height;
	if (ratio > VIEWPORT_RATIO) {
		w = (int)((double)height * VIEWPORT_RATIO);
		h = height;
		x = (width - w) / 2;
		y = 0;
	}
	else {
		w = width;
		h = (int)((double)width / VIEWPORT_RATIO);
		x = 0;
		y = (height - h) / 2;
	}

	glViewport(x, y, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLdouble)width / (GLdouble)height, 0.01, 10000.0);
}

void mouse(int button, int state, int x, int y)
{
	mouse_position.x = x;
	mouse_position.y = y;
}

void motion(int x, int y)
{
	rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
	mouse_position.x = x;
	mouse_position.y = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	const float speed = 1.0;
	const float rotation_speed = 30.0;

	switch (key) {
		case 'w':
			set_camera_speed(&camera, speed);
			break;
		case 's':
			set_camera_speed(&camera, -speed);
			break;
		case 'a':
			set_camera_side_speed(&camera, speed);
			break;
		case 'd':
			set_camera_side_speed(&camera, -speed);
			break;
		case 'q':
			set_camera_lift_speed(&camera, speed);
			break;
		case 'e':
			set_camera_lift_speed(&camera, -speed);
			break;
		case 'j':
			set_camera_horizontal_rotation_speed(&camera, rotation_speed);
			break;
		case 'l':
			set_camera_horizontal_rotation_speed(&camera, -rotation_speed);
			break;
		case 'k':
			set_camera_vertical_rotation_speed(&camera, rotation_speed);
			break;
		case 'i':
			set_camera_vertical_rotation_speed(&camera, -rotation_speed);
			break;
		case '8':
			set_speed(&scene, speed);
			break;
		case '5':
			set_speed(&scene, -speed);
			break;
		case '4':
			set_side_speed(&scene, speed);
			break;
		case '6':
			set_side_speed(&scene, -speed);
			break;
		case '7':
			set_lift_speed(&scene, speed);
			break;
		case '9':
			set_lift_speed(&scene, -speed);
			break;
	}

	glutPostRedisplay();
}

void keyboard_up(unsigned char key, int x, int y)
{
	float position;

	switch (key) {
		case 'w':
		case 's':
			set_camera_speed(&camera, 0.0);
			break;
		case 'a':
		case 'd':
			set_camera_side_speed(&camera, 0.0);
			break;
		case 'q':
		case 'e':
			set_camera_lift_speed(&camera, 0.0);
			break;
		case 'j':
		case 'l':
			set_camera_horizontal_rotation_speed(&camera, 0.0);
			break;
		case 'k':
		case 'i':
			set_camera_vertical_rotation_speed(&camera, 0.0);
			break;
		case '8':
		case '5':
			set_speed(&scene, 0.0);
			break;
		case '4':
		case '6':
			set_side_speed(&scene, 0.0);
			break;
		case '7':
		case '9':
			set_lift_speed(&scene, 0.0);
			break;
	}

	glutPostRedisplay();
}

void idle()
{
	static int last_frame_time = 0;
	int current_time;
	double elapsed_time;

	current_time = glutGet(GLUT_ELAPSED_TIME);
	elapsed_time = (double)(current_time - last_frame_time) / 1000;
	last_frame_time = current_time;

	update_camera(&camera, elapsed_time);
	update_scene(&scene, elapsed_time);

	glutPostRedisplay();
}

