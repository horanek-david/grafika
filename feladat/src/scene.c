#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_soil(Scene* scene)
{
    scene->soil.texture_id = load_texture("textures/grass.jpg"); 

    scene->soil.material.ambient.red = 1.0;
    scene->soil.material.ambient.green = 1.0;
    scene->soil.material.ambient.blue = 1.0;

    scene->soil.material.diffuse.red = 1.0;
    scene->soil.material.diffuse.green = 1.0;
    scene->soil.material.diffuse.blue = 1.0;

    scene->soil.material.specular.red = 0.0;
    scene->soil.material.specular.green = 0.0;
    scene->soil.material.specular.blue = 0.0;

    scene->soil.material.shininess = 0.0;
}

void init_road(Scene* scene)
{
    scene->road.texture_id = load_texture("textures/road.jpg"); 

    scene->road.material.ambient.red = 1.0;
    scene->road.material.ambient.green = 1.0;
    scene->road.material.ambient.blue = 1.0;

    scene->road.material.diffuse.red = 1.0;
    scene->road.material.diffuse.green = 1.0;
    scene->road.material.diffuse.blue = 1.0;

    scene->road.material.specular.red = 0.0;
    scene->road.material.specular.green = 0.0;
    scene->road.material.specular.blue = 0.0;

    scene->road.material.shininess = 0.0;
}

void init_scene(Scene* scene)
{
    init_soil(scene);
    init_road(scene);
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

void draw_grass(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    set_material(&(scene->soil.material));
    glBindTexture(GL_TEXTURE_2D, scene->soil.texture_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<10; i++)
    {
        for(j=0; j<4; j++)
        {
            glPushMatrix();

            glTranslatef(x-i, y-j, z);
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
    }

    glPopMatrix();

}

void draw_grass2(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    //FRONT, BACK GRASS
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->soil.texture_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<16; i++)
    {
        for(j=0; j<1; j++)
        {
            glPushMatrix();

            glTranslatef(x-i, y-j, z);
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
    }

    glPopMatrix();
}

void draw_grass3(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    //SIDE GRASS
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->soil.texture_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<1; i++)
    {
        for(j=0; j<16; j++)
        {
            glPushMatrix();

            glTranslatef(x-i, y-j, z);
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
    }

    glPopMatrix();
}

void draw_road(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->road.texture_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<10; i++)
    {
        for(j=0; j<2; j++)
        {
            glPushMatrix();

            glTranslatef(x-i, y-j, z);
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
    }

    glPopMatrix();
}

void draw_road2(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->road.texture_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<2; i++)
    {
        for(j=0; j<14; j++)
        {
            glPushMatrix();

            glTranslatef(x-i, y-j, z);
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
    }

    glPopMatrix();
}

void draw_thecity(const Scene* scene, float x, float y, float z)
{
    //GRASS
    draw_grass(scene, 4.0, 0.0, 0.0);  //Middle grass.
    draw_grass(scene, 4.0, 6.0, 0.0);

    draw_grass2(scene, 7.0, 9.0, 0.0);  //Front and back grass.
    draw_grass2(scene, 7.0, -6.0, 0.0);
    
    draw_grass3(scene, 7.0, 9.0, 0.0);  //Side grasses.
    draw_grass3(scene, -8.0, 9.0, 0.0);

    //ROAD
    draw_road(scene, 4.0, 2.0, 0.0);  //Middle road.
    draw_road(scene, 4.0, 8.0, 0.0);  //The road behind the small houses.
    draw_road(scene, 4.0, -4.0, 0.0); //The road behind the big house.

    draw_road2(scene, 6.0, 8.0, 0.0);  //Side roads.
    draw_road2(scene, -6.0, 8.0, 0.0);
}

void draw_scene(const Scene* scene)
{
    set_lighting();
    draw_origin();
    
    draw_thecity(scene, 0.0, 0.0, 0.0);
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
