#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

#include <math.h>

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "cube.obj");
    scene->cube_texture_id = load_texture("cube.png");

    load_model(&(scene->hare), "hare.obj");
    scene->hare_texture_id = load_texture("hare.jpg"); 

    scene->chess_texture_id = load_texture("chess.jpg");
    scene->colored_texture_id = load_texture("colored.png"); 
    /*
    scene->chesstable_texture_id = load_texture("chesstable.png");
    */



    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 20.0;

    scene->w = 0.0;
    scene->s = 0.0;

}

void update_scene(Scene* scene, double time)
{
    scene->w += sin(time); 
    scene->s += sin(time);

    if( fabs(sin(scene->s)) > 0.5)
    {
        scene->chesstable_texture_id = load_texture("chesstable.png");
    } else {
        scene->chesstable_texture_id = load_texture("chesstable2.png");
    }
    
}

void set_lighting()
{
    float ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float diffuse_light[] = { 0.8f, 0.8f, 0.8, 1.0f };
    float specular_light[] = { 0.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}


void draw_cube(const Scene* scene)
{
    //Cube
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->cube_texture_id);
    glTranslatef(-0.43, -1.78, 0.08);
    glScalef(0.15, 0.15, 0.15);
    draw_model(&(scene->cube));
    glPopMatrix();
}

void draw_hare(const Scene* scene)
{
    //Hare
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->hare_texture_id);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glTranslatef(0.25, -0.67, 0.0);
    glScalef(0.02, 0.02, 0.02);
    draw_model(&(scene->hare));
    glPopMatrix();
}

void draw_moving_picture(const Scene* scene)
{
    glBindTexture(GL_TEXTURE_2D, scene->hare_texture_id);
    glPushMatrix();
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);

    glTexCoord2f(0, fabs(sin(scene->w)));
    glVertex3f(0, 1, 0);

    glTexCoord2f(1, fabs(sin(scene->w)));
    glVertex3f(1, 1, 0);

    glTexCoord2f(1, 0);
    glVertex3f(1, 0, 0);


    glEnd();
    glPopMatrix();
}

void draw_chesstable1(const Scene* scene)
{
    //Chess
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->chess_texture_id);
    glTranslatef(-2.0, 0.0, 0.0);
    glScalef(2.0, 2.0, 2.0);
    glRotatef(180, 1, 0, 0);
    
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);

    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);

    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 0);

    glTexCoord2f(1, 0);
    glVertex3f(1, 0, 0);

    glEnd();
    glPopMatrix();

}

void draw_chesstable2(const Scene* scene)
{
    //Chesstable
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->chesstable_texture_id);
    glTranslatef(-1.0, 0.0, 0.0);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);

    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);

    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 0);

    glTexCoord2f(1, 0);
    glVertex3f(1, 0, 0);

    glEnd();
    glPopMatrix();
}

void draw_colored(const Scene* scene)
{
    //Colored
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->colored_texture_id);
    glTranslatef(0.0, -1.0, 0.0);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);

    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);

    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 0);

    glTexCoord2f(1, 0);
    glVertex3f(1, 0, 0);

    glEnd();
    glPopMatrix();

}

void draw_scene(const Scene* scene)
{
    set_material(&(scene->material));
    set_lighting();
    draw_origin();
    draw_cube(scene);
    draw_hare(scene);
    draw_moving_picture(scene);
    draw_chesstable1(scene);
    draw_chesstable2(scene);
    draw_colored(scene);


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

