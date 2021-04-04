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

    init_car(scene);
}

void init_car(Scene* scene)
{
    /* Load porsche */
    scene->car.is_light_on = FALSE;

    load_model(&(scene->car.body), "models/porsche01.obj");
    load_model(&(scene->car.tire_front), "models/porsche02.obj");
    load_model(&(scene->car.tire_back), "models/porsche03.obj");
    load_model(&(scene->car.glass), "models/porsche04.obj");
    load_model(&(scene->car.lamp), "models/porsche05.obj");
    scene->car.texture_body_id = load_texture("textures/porsche01.bmp");
    scene->car.texture_tire_id = load_texture("textures/porsche02.bmp");

    scene->car.material_car_body.ambient.red = 1.0;
    scene->car.material_car_body.ambient.green = 1.0;
    scene->car.material_car_body.ambient.blue = 1.0;
    scene->car.material_car_body.ambient.alpha = 1.0;

    scene->car.material_car_body.diffuse.red = 1.0;
    scene->car.material_car_body.diffuse.green = 1.0;
    scene->car.material_car_body.diffuse.blue = 1.0;
    scene->car.material_car_body.diffuse.alpha = 1.0;

    scene->car.material_car_body.specular.red = 1.0;
    scene->car.material_car_body.specular.green = 1.0;
    scene->car.material_car_body.specular.blue = 1.0;
    scene->car.material_car_body.specular.alpha = 1.0;

    scene->car.material_car_body.shininess = 0.0;

    scene->car.material_car_glass.ambient.red = 0.2f;
    scene->car.material_car_glass.ambient.green = 0.2f;
    scene->car.material_car_glass.ambient.blue = 0.2f;
    scene->car.material_car_glass.ambient.alpha = 0.2f;

    scene->car.material_car_glass.diffuse.red = 0.2f;
    scene->car.material_car_glass.diffuse.green = 0.2f;
    scene->car.material_car_glass.diffuse.blue = 0.2f;
    scene->car.material_car_glass.diffuse.alpha = 0.2f;

    scene->car.material_car_glass.specular.red = 0.2f;
    scene->car.material_car_glass.specular.green = 0.2f;
    scene->car.material_car_glass.specular.blue = 0.2f;
    scene->car.material_car_glass.specular.alpha = 0.2f;

    scene->car.material_car_lamp.ambient.red = 1.0f;
    scene->car.material_car_lamp.ambient.green = 1.0f;
    scene->car.material_car_lamp.ambient.blue = 1.0f;
    scene->car.material_car_lamp.ambient.alpha = 1.0f;
    
    scene->car.material_car_lamp.diffuse.red = 1.0f;
    scene->car.material_car_lamp.diffuse.green = 1.0f;
    scene->car.material_car_lamp.diffuse.blue = 1.0f;
    scene->car.material_car_lamp.ambient.alpha = 0.5f;
    
}

void update_scene(Scene* scene, double time)
{
    float x, i, a, r;
    r = 0.8;    /* kerék átmérője */
    x = scene->car.position.x;

    scene->car.position.x += scene->car.speed.x * time;
    scene->car.position.y += scene->car.speed.y * time;
    scene->car.position.z += scene->car.speed.z * time;

    /* Kerék forgása ha magy az autó előre hátra */
    i = (scene->car.position.x - x);
    a = (i * 180) / (r * 3.14);
    scene->car.rotate += a;

    /* Autó elfordulása fok*/
    scene->car.rotatea += scene->car.speedz * time * 5;

    /* Kerék elfordulása max 30 fok engedve*/
    scene->car.rotatez += scene->car.speedz * time * 30;
    
    if(scene->car.rotatez > 30)
        scene->car.rotatez = 30;

    if(scene->car.rotatez < -30)
        scene->car.rotatez = -30;

    /* Autó forgási középpont */
    scene->car.rotcen = tan(scene->car.rotatez) * 2.36;

    /* Autó lámpa kapcsolása */
    if (scene->car.is_light_on) {
        scene->car.material_car_lamp.ambient.red = 1.0f;
        scene->car.material_car_lamp.ambient.green = 1.0f;
        scene->car.material_car_lamp.ambient.blue = 1.0f;
    }
    else{
        scene->car.material_car_lamp.ambient.red = 0.0f;
        scene->car.material_car_lamp.ambient.green = 0.0f;
        scene->car.material_car_lamp.ambient.blue = 0.0f;
    }


}

void set_car_lamp_l(float x, float y, float z)
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { x, y, z, 1.0f };
    float spot_direction[] = { -1.0, 0.0, 0.0};

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT2, GL_POSITION, position);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);         
}

void set_car_lamp_r(float x, float y, float z)
{
    float ambient_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { x, y, z, 1.0f };
    float spot_direction[] = { -1.0, 0.0, 0.0};

    glLightfv(GL_LIGHT3, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT3, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT3, GL_POSITION, position);
    glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 90.0);
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 2.0); 
}

void set_car_speed(Scene* scene, float x)
{
    scene->car.speed.x = x;
}

void set_car_side_speed(Scene* scene, float y)
{
    //scene->car.speed.y = y;
    scene->car.speedz = y;
}

void draw_car(const Scene* scene){
    
    float x, y, z;
    x = scene->car.position.x;
    y = scene->car.position.y;
    z = scene->car.position.z + 0.65;

    glPushMatrix();
    
    /* Pozició */

    /* Autó elfordulás */
    glTranslatef(x, y, z);
    glRotatef(scene->car.rotatea, 0.0, 0.0, 1.0);
    


    /* Üveg */
    glPushMatrix();
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

        set_material(&(scene->car.material_car_glass));
        draw_model(&(scene->car.glass));

        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
    glPopMatrix();

    /* Auto lámpa */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);
        set_material(&(scene->car.material_car_lamp));
        glTranslatef(-0.001, 0.0, 0.0);
        draw_model(&(scene->car.lamp));

        glPushMatrix();
            glTranslatef(-2.75, 0.65, 0.0);
            glRotatef(15.0, 0.0, 0.0, 1.0);
            set_car_lamp_l(0, 0, 0);

            if(scene->car.is_light_on)
            {
                glEnable(GL_LIGHT2);
            }
            else
            {
                glDisable(GL_LIGHT2);
            }  
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-2.85, -0.55, 0.0);
            glRotatef(30.0, 0.0, 0.0, 1.0);
            set_car_lamp_r(0, 0, 0);

            if(scene->car.is_light_on)
            {
                glEnable(GL_LIGHT3);
            }
            else
            {
                glDisable(GL_LIGHT3);
            }
        glPopMatrix();
    glPopMatrix();

    /* Auto váz */
    glPushMatrix();
        set_material(&(scene->car.material_car_body));
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_body_id);
        draw_model(&(scene->car.body));
    glPopMatrix(); 

    /* Jobb hátsó kerék */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glTranslatef(0, 0.55, -0.3);
        glRotatef(scene->car.rotate, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_back));
    glPopMatrix();

    /* Bal hátsó kerék */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glRotated(180, 0.0, 0.0, 1.0);
        glTranslatef(0, 0.55, -0.3);
        glRotatef(-scene->car.rotate, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_back));
    glPopMatrix();

    /* Jobb első kerék */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glTranslatef(-2.36, 0.6, -0.32);
        /* elfordulás */
        glRotatef(scene->car.rotatez, 0.0, 0.0, 1.0);
        /* forgás */
        glRotatef(scene->car.rotate, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_front));
    glPopMatrix();

    /* Bal első kerék */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glRotated(180, 0.0, 0.0, 1.0);
        glTranslatef(2.36, 0.6, -0.32);
        /* elfordulás */
        glRotatef(scene->car.rotatez, 0.0, 0.0, 1.0);
        /* forgás */
        glRotatef(-scene->car.rotate, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_front));
    glPopMatrix();

    glPopMatrix();
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

    glPushMatrix();
    glTranslatef(10.0, 25.0, 0.0);
    draw_car(scene);
    glPopMatrix();

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
