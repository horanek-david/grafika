#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    //TABLE
    load_model(&(scene->table), "models/table.obj");
    scene->texture_table_id = load_texture("textures/table_col.png");

    //CHAIR
    load_model(&(scene->chair), "models/chair.obj");
    scene->texture_chair_id = load_texture("textures/chair_01_Base_Color.png"); 

    //CHAIR
    load_model(&(scene->floor), "models/floor.obj");
    scene->texture_floor_id = load_texture("textures/Material _25_Base_Color.png");


    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 0.0;
    scene->material.diffuse.green = 0.0;
    scene->material.diffuse.blue = 0.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;
}

void set_lighting()
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 0.0f, 0.0f, 0.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
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

void draw_table(const Scene* scene, float x, float y, float z)
{
    glPushMatrix();

    glScalef(2.0, 2.0, 2.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_table_id);
    draw_model(&(scene->table));

    glPopMatrix();
}

void draw_chair(const Scene* scene, float x, float y, float z, float degree)
{
    glPushMatrix();

    glRotatef(degree, 0.0, 0.0, 1.0);
    glTranslatef(x, y, z);
    glBindTexture(GL_TEXTURE_2D, scene->texture_chair_id);
    draw_model(&(scene->chair));

    glPopMatrix();
}

void draw_floor(const Scene* scene)
{
    glPushMatrix();

    glRotatef(90, 0.0, 1.0, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_floor_id);
    draw_model(&(scene->floor));

    glTranslatef(0.0, 0.0, -2.39);
    draw_model(&(scene->floor));

    glTranslatef(0.0, -4.0, 2.39);
    draw_model(&(scene->floor));

    glTranslatef(0.0, 0.0, -2.39);
    draw_model(&(scene->floor));

    glPopMatrix();
}

void draw_scene(const Scene* scene)
{
    
    set_material(&(scene->material));
    set_lighting();

    draw_origin();

    /*
        1 table
    */
    draw_table(scene, 0.0, 0.0, 0.0);

    /*
        4 chair
    */
    draw_chair(scene, -0.6, 0.0, 0.0, 0.0);
    draw_chair(scene, -0.6, 0.0, 0.0, 90.0);
    draw_chair(scene, -0.6, 0.0, 0.0, -90.0);
    draw_chair(scene, -0.6, 0.0, 0.0, 180.0);

    /*
        1 floor
    */
    //draw_floor(scene);


}

void draw_origin()
{

    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);

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

    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

}
