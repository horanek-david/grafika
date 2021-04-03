#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    //TABLE
    load_model(&(scene->table), "models/table.obj");
    scene->texture_table_id = load_texture("textures/chair_01_Base_Color.png");

    //CHAIR
    load_model(&(scene->chair), "models/chair.obj");
    scene->texture_chair_id = load_texture("textures/chair_01_Base_Color.png"); 

    //FLOOR
    load_model(&(scene->floor), "models/floor.obj");
    scene->texture_floor_id = load_texture("textures/Material _25_Base_Color.png");

    //HOUSE1
    load_model(&(scene->house), "models/house.obj");
    scene->texture_house_id = load_texture("textures/Diffuse.png");

    //HOUSE2
    load_model(&(scene->house2), "models/house2.obj");
    scene->texture_house2_id = load_texture("textures/Farmhouse Texture.jpg");

    //GRASS
    scene->texture_grass_id = load_texture("textures/grass.jpg");



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
    glTranslatef(x, y, z);
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

void draw_house(const Scene* scene)
{
    glPushMatrix();

    glScalef(2.0, 2.0, 2.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house_id);
    draw_model(&(scene->house));

    /*
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    */

    glPopMatrix();
}

void draw_house2(const Scene* scene)
{
    glPushMatrix();

    glScalef(25.0, 25.0, 25.0);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glTranslatef(0.1, -0.4, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house2_id);
    draw_model(&(scene->house2));

    glTranslatef(0.0, -0.4, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house2_id);
    draw_model(&(scene->house2));

    glTranslatef(0.0, 1.2, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house2_id);
    draw_model(&(scene->house2));

    glPopMatrix();
}

void draw_grass(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_grass_id);
    glScalef(5.0, 5.0, 5.0);


    for(i=0; i<8; i++)
    {
        for(j=0; j<3; j++)
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

void draw_scene(const Scene* scene)
{
    
    set_material(&(scene->material));
    set_lighting();

    draw_origin();

    /*
        1 table
    */
    draw_table(scene, 0.0, 0.0, 0.2);

    /*
        4 chair
    */
    draw_chair(scene, -0.6, 0.0, 0.4, 0.0);
    draw_chair(scene, -0.6, 0.0, 0.4, 90.0);
    draw_chair(scene, -0.6, 0.0, 0.4, -90.0);
    draw_chair(scene, -0.6, 0.0, 0.4, 180.0);

    /*
        1 floor
    */
    //draw_floor(scene);

    /*
        1 house
    */
    draw_house(scene);

    /*
        2 house2
    */
    draw_house2(scene);

    /*
        1 block of grass
    */
    draw_grass(scene, 2.0, 0.0, 0.0);


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
