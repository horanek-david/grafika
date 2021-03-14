#include "callbacks.h"
#include "init.h"
#include <GL/glut.h>
#include <stdio.h>


void set_callbacks()
{
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
    glutIdleFunc(idle);
}

/**
 * Main function.
 */
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    int window = glutCreateWindow("House with a camera");
    glutSetWindow(window);

    init_opengl();

    init_scene(&scene);
    init_camera(&camera);
    set_callbacks();
    glutMainLoop();

    return 0;
}

