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

void init_mainhouse(Scene* scene)
{
    load_model(&(scene->house.model), "models/mainhouse.obj");
    scene->house.texture_id = load_texture("textures/mainhouse.png"); 

    scene->house.material.ambient.red = 1.0;
    scene->house.material.ambient.green = 1.0;
    scene->house.material.ambient.blue = 1.0;

    scene->house.material.diffuse.red = 1.0;
    scene->house.material.diffuse.green = 1.0;
    scene->house.material.diffuse.blue = 1.0;

    scene->house.material.specular.red = 0.0;
    scene->house.material.specular.green = 0.0;
    scene->house.material.specular.blue = 0.0;

    scene->house.material.shininess = 0.0;
    
    init_fence(&(scene->house.fence));
}

void init_house2(Scene* scene)
{
    load_model(&(scene->house2.model), "models/house2.obj");
    scene->house2.texture_id = load_texture("textures/house2.jpg"); 

    scene->house2.material.ambient.red = 1.0;
    scene->house2.material.ambient.green = 1.0;
    scene->house2.material.ambient.blue = 1.0;

    scene->house2.material.diffuse.red = 1.0;
    scene->house2.material.diffuse.green = 1.0;
    scene->house2.material.diffuse.blue = 1.0;

    scene->house2.material.specular.red = 0.0;
    scene->house2.material.specular.green = 0.0;
    scene->house2.material.specular.blue = 0.0;

    scene->house2.material.shininess = 0.0;
    
    init_fence(&(scene->house2.fence));
}

void init_house3(Scene* scene)
{
    load_model(&(scene->house3.model), "models/house3.obj");
    scene->house3.texture_id = load_texture("textures/house3.jpg"); 

    scene->house3.material.ambient.red = 1.0;
    scene->house3.material.ambient.green = 1.0;
    scene->house3.material.ambient.blue = 1.0;

    scene->house3.material.diffuse.red = 1.0;
    scene->house3.material.diffuse.green = 1.0;
    scene->house3.material.diffuse.blue = 1.0;

    scene->house3.material.specular.red = 0.0;
    scene->house3.material.specular.green = 0.0;
    scene->house3.material.specular.blue = 0.0;

    scene->house3.material.shininess = 0.0;
    
    init_fence(&(scene->house3.fence));
}

void init_fence(Railing* fence)
{
    load_model(&(fence->model), "models/fence.obj");
    fence->texture_id = load_texture("textures/fence.png"); 

    fence->material.ambient.red = 1.0;
    fence->material.ambient.green = 1.0;
    fence->material.ambient.blue = 1.0;

    fence->material.diffuse.red = 1.0;
    fence->material.diffuse.green = 1.0;
    fence->material.diffuse.blue = 1.0;

    fence->material.specular.red = 0.0;
    fence->material.specular.green = 0.0;
    fence->material.specular.blue = 0.0;

    fence->material.shininess = 0.0;
}

void init_barrier(Scene* scene)
{
    load_model(&(scene->barrier.model), "models/barrier.obj");
    scene->barrier.texture_id = load_texture("textures/barrier.png"); 

    scene->barrier.material.ambient.red = 1.0;
    scene->barrier.material.ambient.green = 1.0;
    scene->barrier.material.ambient.blue = 1.0;

    scene->barrier.material.diffuse.red = 1.0;
    scene->barrier.material.diffuse.green = 1.0;
    scene->barrier.material.diffuse.blue = 1.0;

    scene->barrier.material.specular.red = 0.0;
    scene->barrier.material.specular.green = 0.0;
    scene->barrier.material.specular.blue = 0.0;

    scene->barrier.material.shininess = 0.0;
}

void init_scene(Scene* scene)
{
    init_soil(scene);
    init_road(scene);
    init_mainhouse(scene);
    init_house2(scene);
    init_house3(scene);
    init_barrier(scene);
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
    set_material(&(scene->soil.material));
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
    set_material(&(scene->soil.material));
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
    set_material(&(scene->road.material));
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
    set_material(&(scene->road.material));
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

void draw_mainhouse(const Scene* scene, float x, float y, float z)
{
    
    glPushMatrix();
    glTranslatef(x, y, z);

    /*MAIN HOUSE*/
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    set_material(&(scene->house.material));
    glBindTexture(GL_TEXTURE_2D, scene->house.texture_id);
    draw_model(&(scene->house));
    glPopMatrix();

    /*FENCES*/
    draw_fence(&(scene->house.fence));

    glPopMatrix();
}

void draw_house2(const Scene* scene,  float x, float y, float z)
{
    int i;

    glPushMatrix();
    glTranslatef(x, y, z);

    /*NEIGHBOUR'S HOUSE*/
    glPushMatrix();

    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glScalef(25.0, 25.0, 25.0);
    glTranslatef(0.1, -0.08, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->house2.texture_id);
    draw_model(&(scene->house2.model));

    glPopMatrix();

    /*FENCES*/
    draw_fence(&(scene->house.fence));

    glPopMatrix();
}

void draw_house3(const Scene* scene, float x, float y, float z)
{

    glPushMatrix();
    glTranslatef(x, y, z);

    /*FRONT NEIGHBOUR*/
    glPushMatrix();

    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->house3.texture_id);
    draw_model(&(scene->house3.model));

    glPopMatrix();

    /*FENCES*/
    draw_fence2(&(scene->house.fence));

    glPopMatrix();
}

void draw_fence(const Railing* fence)
{
    int i;

    /*LEFT SIDE FENCES*/
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(4.0, 2.5, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<3; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(fence->model));
    }
    glPopMatrix();

    /*FRONT FENCES*/
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(5.0, -1.5, 0.0);
    draw_model(&(fence->model));

    glTranslatef(0.0, 6.5, 0.0);
    draw_model(&(fence->model));
    glPopMatrix();

    /*RIGHT SIDE FENCES*/
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(-7.5, 2.5, 0.0);
    draw_model(&(fence->model));
    
    for(i=0; i<3; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(fence->model));
    }
    glPopMatrix();

    /*BACK FENCES*/
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-12.0, -1.5, 0.0);
    draw_model(&(fence->model));
    glTranslatef(0.0, 6.5, 0.0);
    draw_model(&(fence->model));
    glTranslatef(0.0, -2.15, 0.0);
    draw_model(&(fence->model));


    glPopMatrix();
}

void draw_fence2(const Railing* fence)
{
    int i;
    
    /*FRONT1*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(5.0, 5.0, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 4.0, 0.0);
        draw_model(&(fence->model));
    }
    
    glPopMatrix();

    /*FRONT2*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(5.0, -5.0, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(fence->model));
    }
    
    glPopMatrix();

    /*BACK1*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(-15.0, 5.0, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 4.0, 0.0);
        draw_model(&(fence->model));
    }
    
    glPopMatrix();

    /*BACK2*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(-15.0, -5.0, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(fence->model));
    }
    
    glPopMatrix();


    /*SIDE1*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(-23.5, -2.5, 0.0);
    draw_model(&(fence->model));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 3.8, 0.0);
        draw_model(&(fence->model));
    }
    glPopMatrix();

    /*SIDE2*/
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, fence->texture_id);
    glTranslatef(23.5, -2.5, 0.0);
    draw_model(&(fence->model));
    
    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 3.8, 0.0);
        draw_model(&(fence->model));
    }
    glPopMatrix();

}

void draw_barrier(const Scene* scene)
{   
    int i;
    float change = 1.0/0.04;

    /*LEFT SIDE*/
    glPushMatrix();

    glScalef(0.04, 0.04, 0.04);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->barrier.texture_id);
    glTranslatef(45.0 * change, 35.0 * change, 0.0 *change);
    draw_model(&(scene->barrier.model));

    for(i=0; i<62; i++)
    {
        glTranslatef(-1.1 * change, 0.0 * change, 0.0 * change);
        draw_model(&(scene->barrier.model));
    }
    glPopMatrix();

    /*RIGHT SIDE*/
    glPushMatrix();

    glScalef(0.04, 0.04, 0.04);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->barrier.texture_id);
    glTranslatef(45.0 * change, -35.0 * change, 0.0 *change);
    draw_model(&(scene->barrier.model));

    for(i=0; i<62; i++)
    {
        glTranslatef(-1.1 * change, 0.0 * change, 0.0 * change);
        draw_model(&(scene->barrier.model));
    }
    glPopMatrix();

    /*BACK*/
    glPushMatrix();

    glScalef(0.04, 0.04, 0.04);
    glBindTexture(GL_TEXTURE_2D, scene->barrier.texture_id);
    glTranslatef(-33.4 * change, -25.45 * change, 0.0 *change);
    draw_model(&(scene->barrier.model));

    for(i=0; i<62; i++)
    {
        glTranslatef(1.1 * change, 0.0 * change, 0.0 * change);
        draw_model(&(scene->barrier.model));
    }
    glPopMatrix();

    /*FRONT*/
    glPushMatrix();

    glScalef(0.04, 0.04, 0.04);
    glBindTexture(GL_TEXTURE_2D, scene->barrier.texture_id);
    glTranslatef(-33.4 * change, 45.0 * change, 0.0 *change);
    draw_model(&(scene->barrier.model));

    for(i=0; i<62; i++)
    {
        glTranslatef(1.1 * change, 0.0 * change, 0.0 * change);
        draw_model(&(scene->barrier.model));
    }
    glPopMatrix();

}

void draw_thecity(const Scene* scene)
{
    /*GRASS*/
    draw_grass(scene, 4.0, 0.0, 0.0);  /*Middle grass.*/
    draw_grass(scene, 4.0, 6.0, 0.0);

    draw_grass2(scene, 7.0, 9.0, 0.0);  /*Front and back grass.*/
    draw_grass2(scene, 7.0, -6.0, 0.0);
    
    draw_grass3(scene, 7.0, 9.0, 0.0);  /*Side grasses.*/
    draw_grass3(scene, -8.0, 9.0, 0.0);

    /*ROAD*/
    draw_road(scene, 4.0, 2.0, 0.0);  /*Middle road.*/
    draw_road(scene, 4.0, 8.0, 0.0);  /*The road behind the small houses.*/
    draw_road(scene, 4.0, -4.0, 0.0); /*The road behind the big house.*/

    draw_road2(scene, 6.0, 8.0, 0.0);  /*Side roads.*/
    draw_road2(scene, -6.0, 8.0, 0.0);

    /*HOUSES*/
    draw_mainhouse(scene, 0.0, -1.0, 0.0);  /*The main house of the small houses.*/

    draw_house2(scene, -15.0, -1.0, 0.0);   /*Small houses on the left and right side of the main house.*/
    draw_house2(scene, 15.0, -1.0, 0.0);

    draw_house3(scene, 0.0, 20.0, 0.0);     /*The big house in front of the main house.*/

    /*BARRIER*/
    draw_barrier(scene);

}

void draw_scene(const Scene* scene)
{
    set_lighting();
    draw_origin();
    
    draw_thecity(scene);
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
