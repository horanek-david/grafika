#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    //TABLE
    load_model(&(scene->table), "models/table.obj");
    scene->texture_table_id = load_texture("textures/chair_initialShadingGroup_BaseColor.png");

    //CHAIR
    load_model(&(scene->chair), "models/chair.obj");
    scene->texture_chair_id = load_texture("textures/chair_initialShadingGroup_BaseColor.png"); 

    //CHAIR
    load_model(&(scene->rchair), "models/rockingchair.obj");
    scene->texture_rchair_id = load_texture("textures/chair_initialShadingGroup_BaseColor.png");

    //FLOOR
    load_model(&(scene->floor), "models/floor.obj");
    scene->texture_floor_id = load_texture("textures/Material _25_Base_Color.png");

    //HOUSE1
    load_model(&(scene->house), "models/house.obj");
    scene->texture_house_id = load_texture("textures/Diffuse.png");

    //HOUSE2
    load_model(&(scene->house2), "models/house2.obj");
    scene->texture_house2_id = load_texture("textures/Farmhouse Texture.jpg");

    //HOUSE3
    load_model(&(scene->house3), "models/house3.obj");
    scene->texture_house3_id = load_texture("textures/Big_Old_House_C.jpg");

    //FENCE
    load_model(&(scene->fence), "models/fence.obj");
    scene->texture_fence_id = load_texture("textures/Map.png");

    //GRASS
    scene->texture_grass_id = load_texture("textures/grass.jpg");

    //ROAD
    scene->texture_road_id = load_texture("textures/road.jpg");



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

void draw_rockingchair(const Scene* scene, float x, float y, float z, float degree)
{
    glPushMatrix();

    glScalef(0.05, 0.05, 0.05);
    glRotatef(degree, 0.0, 0.0, 1.0);
    glTranslatef(x, y, z);
    glBindTexture(GL_TEXTURE_2D, scene->texture_rchair_id);
    draw_model(&(scene->rchair));

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

void draw_house(const Scene* scene, float x, float y, float z)
{
    
    glPushMatrix();
    glTranslatef(x, y, z);

    //MAIN HOUSE
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house_id);
    draw_model(&(scene->house));
    glPopMatrix();

    //FENCES
    draw_fence(scene);

    // TABLE
    draw_table(scene, 0.0, 0.0, 0.2);

    //ROCKINGCHAIR
    draw_rockingchair(scene, 0.0, 75.0, 18.0, -135);

    // CHAIRS
    draw_chair(scene, -0.6, 0.0, 0.4, 0.0);
    draw_chair(scene, -0.6, 0.0, 0.4, 90.0);
    draw_chair(scene, -0.6, 0.0, 0.4, -90.0);
    draw_chair(scene, -0.6, 0.0, 0.4, 180.0);
    
    glPopMatrix();

}

void draw_house2(const Scene* scene,  float x, float y, float z)
{
    int i;

    glPushMatrix();
    glTranslatef(x, y, z);

    //NEIGHBOUR HOUSE
    glPushMatrix();

    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glScalef(25.0, 25.0, 25.0);
    glTranslatef(0.1, -0.08, 0.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house2_id);
    draw_model(&(scene->house2));

    glPopMatrix();

    //FENCES
    draw_fence(scene);

    glPopMatrix();
}

void draw_house3(const Scene* scene, float x, float y, float z)
{

    glPushMatrix();
    glTranslatef(x, y, z);

    //FRONT NEIGHBOUR
    glPushMatrix();

    glRotatef(-90.0, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_house3_id);
    draw_model(&(scene->house3));

    glPopMatrix();

    draw_fence2(scene);
    
    glPopMatrix();
}

void draw_grass(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_grass_id);
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

void draw_road(const Scene* scene, float x, float y, float z)
{
    int i;
    int j;

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->texture_road_id);
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
    glBindTexture(GL_TEXTURE_2D, scene->texture_road_id);
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

void draw_fence(const Scene* scene)
{
    int i;

    //LEFT SIDE FENCES
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(4.0, 2.5, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<3; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(scene->fence));
    }
    glPopMatrix();

    //FRONT FENCES
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(5.0, -1.5, 0.0);
    draw_model(&(scene->fence));

    glTranslatef(0.0, 6.5, 0.0);
    draw_model(&(scene->fence));
    glPopMatrix();

    //RIGHT SIDE FENCES
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(-7.5, 2.5, 0.0);
    draw_model(&(scene->fence));
    
    for(i=0; i<3; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(scene->fence));
    }
    glPopMatrix();

    //BACK FENCES
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glTranslatef(-12.0, -1.5, 0.0);
    draw_model(&(scene->fence));
    glTranslatef(0.0, 6.5, 0.0);
    draw_model(&(scene->fence));
    glTranslatef(0.0, -2.15, 0.0);
    draw_model(&(scene->fence));


    glPopMatrix();
}

void draw_fence2(const Scene* scene)
{
    int i;
    
    //FRONT1
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(5.0, 5.0, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 4.0, 0.0);
        draw_model(&(scene->fence));
    }
    
    glPopMatrix();

    //FRONT2
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(5.0, -5.0, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(scene->fence));
    }
    
    glPopMatrix();

    //BACK1
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(-15.0, 5.0, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 4.0, 0.0);
        draw_model(&(scene->fence));
    }
    
    glPopMatrix();

    //BACK2
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(-15.0, -5.0, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, -4.0, 0.0);
        draw_model(&(scene->fence));
    }
    
    glPopMatrix();

    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glRotatef(-90, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(-15.0, 0.0, 0.0);
    draw_model(&(scene->fence));

    glPopMatrix();

    //SIDE1
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(-23.5, -2.5, 0.0);
    draw_model(&(scene->fence));

    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 3.8, 0.0);
        draw_model(&(scene->fence));
    }
    glPopMatrix();

    //SIDE2
    glPushMatrix();

    glScalef(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->texture_fence_id);
    glTranslatef(23.5, -2.5, 0.0);
    draw_model(&(scene->fence));
    
    for(i=0; i<4; i++)
    {
        glTranslatef(0.0, 3.8, 0.0);
        draw_model(&(scene->fence));
    }
    glPopMatrix();

    

}

void draw_city(const Scene* scene, float x, float y, float z)
{
    //MAIN HOUSE
    draw_house(scene, 0.0, -1.0, 0.0);

    //NEIGHBOURS
    draw_house2(scene, -15.0, -1.0, 0.0);
    draw_house2(scene, 15.0, -1.0, 0.0);

    //FRONT NEIGHBOUR
    draw_house3(scene, 0.0, 20.0, 0.0);

    //GRASS
    draw_grass(scene, 4.0, 0.0, 0.0);
    draw_grass(scene, 4.0, 6.0, 0.0);

    //ROAD
    draw_road(scene, 4.0, 2.0, 0.0);
    draw_road(scene, 4.0, 8.0, 0.0);
    draw_road(scene, 4.0, -4.0, 0.0);

    //ROAD2
    draw_road2(scene, 6.0, 8.0, 0.0);
    draw_road2(scene, -6.0, 8.0, 0.0);

}

void draw_scene(const Scene* scene)
{
    
    set_material(&(scene->material));
    set_lighting();

    draw_origin();

    draw_city(scene, 0.0, 0.0, 0.0);
    //draw_fence2(scene);

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
