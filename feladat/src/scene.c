#include "scene.h"

#include <GL/glut.h>

#include <math.h>

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

void init_tree(Scene* scene)
{
    load_model(&(scene->tree.trunk), "models/trunk.obj");
    load_model(&(scene->tree.leaves), "models/leaves.obj");

    /* TRUNK */
    scene->tree.material_trunk.ambient.red = 0.2295f;
    scene->tree.material_trunk.ambient.green = 0.08825f;
    scene->tree.material_trunk.ambient.blue = 0.0275f;
    scene->tree.material_trunk.ambient.alpha =1.0f;

    scene->tree.material_trunk.diffuse.red = 0.5508f;
    scene->tree.material_trunk.diffuse.green = 0.2118f;
    scene->tree.material_trunk.diffuse.blue = 0.066f;
    scene->tree.material_trunk.diffuse.alpha =1.0f;

    scene->tree.material_trunk.specular.red = 0.580594f;
    scene->tree.material_trunk.specular.green = 0.223257f;
    scene->tree.material_trunk.specular.blue = 0.0695701f;
    scene->tree.material_trunk.specular.alpha =1.0f;

    scene->tree.material_trunk.shininess = 51.2f;

    /* LEAVES */
    scene->tree.material_leaves.ambient.red = 0.0215f;
    scene->tree.material_leaves.ambient.green = 0.1745f;
    scene->tree.material_leaves.ambient.blue = 0.0215f;
    scene->tree.material_leaves.ambient.alpha =0.55f;

    scene->tree.material_leaves.diffuse.red = 0.07568f;
    scene->tree.material_leaves.diffuse.green = 0.61424f;
    scene->tree.material_leaves.diffuse.blue = 0.07568f;
    scene->tree.material_leaves.diffuse.alpha =0.55f;

    scene->tree.material_leaves.specular.red = 0.633f;
    scene->tree.material_leaves.specular.green = 0.727811f;
    scene->tree.material_leaves.specular.blue = 0.633f;
    scene->tree.material_leaves.specular.alpha =0.55f;

    scene->tree.material_leaves.shininess = 76.8f;
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

void init_car(Scene* scene)
{
    scene->car.is_light_on = FALSE;

    load_model(&(scene->car.body), "models/porsche01.obj");
    load_model(&(scene->car.tire_front), "models/porsche02.obj");
    load_model(&(scene->car.tire_back), "models/porsche03.obj");
    load_model(&(scene->car.glass), "models/porsche04.obj");
    load_model(&(scene->car.lamp), "models/porsche05.obj");
    scene->car.texture_body_id = load_texture("textures/porsche01.bmp");
    scene->car.texture_tire_id = load_texture("textures/porsche02.bmp");

    /* Car's body materials */
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

    /* Car's glass materials */
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

    /* Car's lamp materials */
    scene->car.material_car_lamp.ambient.red = 1.0f;
    scene->car.material_car_lamp.ambient.green = 1.0f;
    scene->car.material_car_lamp.ambient.blue = 1.0f;
    scene->car.material_car_lamp.ambient.alpha = 1.0f;
    
    scene->car.material_car_lamp.diffuse.red = 1.0f;
    scene->car.material_car_lamp.diffuse.green = 1.0f;
    scene->car.material_car_lamp.diffuse.blue = 1.0f;
    scene->car.material_car_lamp.ambient.alpha = 0.5f;
    
}

void init_rocking_chair(Scene* scene)
{
    scene->rocking_chair.furniture_rocking_direction = 1.0;

    load_model(&(scene->rocking_chair.model), "models/rockingchair.obj");
    scene->rocking_chair.texture_id = load_texture("textures/wood.jpg"); 

    scene->rocking_chair.material.ambient.red = 1.0;
    scene->rocking_chair.material.ambient.green = 1.0;
    scene->rocking_chair.material.ambient.blue = 1.0;

    scene->rocking_chair.material.diffuse.red = 1.0;
    scene->rocking_chair.material.diffuse.green = 1.0;
    scene->rocking_chair.material.diffuse.blue = 1.0;

    scene->rocking_chair.material.specular.red = 0.0;
    scene->rocking_chair.material.specular.green = 0.0;
    scene->rocking_chair.material.specular.blue = 0.0;

    scene->rocking_chair.material.shininess = 0.0;
}

void init_chair(Scene* scene)
{
    load_model(&(scene->chair.model), "models/chair.obj");
    scene->chair.texture_id = load_texture("textures/wood.jpg"); 

    scene->chair.material.ambient.red = 1.0;
    scene->chair.material.ambient.green = 1.0;
    scene->chair.material.ambient.blue = 1.0;

    scene->chair.material.diffuse.red = 1.0;
    scene->chair.material.diffuse.green = 1.0;
    scene->chair.material.diffuse.blue = 1.0;

    scene->chair.material.specular.red = 0.0;
    scene->chair.material.specular.green = 0.0;
    scene->chair.material.specular.blue = 0.0;

    scene->chair.material.shininess = 0.0;
}

void init_table(Scene* scene)
{
    load_model(&(scene->table.model), "models/table.obj");
    scene->table.texture_id = load_texture("textures/wood.jpg"); 

    scene->table.material.ambient.red = 1.0;
    scene->table.material.ambient.green = 1.0;
    scene->table.material.ambient.blue = 1.0;

    scene->table.material.diffuse.red = 1.0;
    scene->table.material.diffuse.green = 1.0;
    scene->table.material.diffuse.blue = 1.0;

    scene->table.material.specular.red = 0.0;
    scene->table.material.specular.green = 0.0;
    scene->table.material.specular.blue = 0.0;

    scene->table.material.shininess = 0.0;
}

void init_dresser(Scene* scene)
{
    load_model(&(scene->dresser.model), "models/dresser.obj");
    scene->dresser.texture_id = load_texture("textures/wood.jpg"); 

    scene->dresser.material.ambient.red = 1.0;
    scene->dresser.material.ambient.green = 1.0;
    scene->dresser.material.ambient.blue = 1.0;

    scene->dresser.material.diffuse.red = 1.0;
    scene->dresser.material.diffuse.green = 1.0;
    scene->dresser.material.diffuse.blue = 1.0;

    scene->dresser.material.specular.red = 0.0;
    scene->dresser.material.specular.green = 0.0;
    scene->dresser.material.specular.blue = 0.0;

    scene->dresser.material.shininess = 0.0;
}

void init_scene(Scene* scene)
{
    scene->sun_brightness = 0.0;
    
    init_soil(scene);
    init_tree(scene);
    init_road(scene);
    init_mainhouse(scene);
    init_house2(scene);
    init_house3(scene);
    init_barrier(scene);
    init_car(scene);
    init_rocking_chair(scene);
    init_chair(scene);
    init_table(scene);
    init_dresser(scene);
}

void update_scene(Scene* scene, Camera* camera, double time)
{

    /* CAR */
    float x, n, i, j, r;
    float alpha, beta, a, b, c;
    float speed, around;
    time = time * 1.2;
    
    speed = scene->car.speedz * time;  /* For side movement */
    x = scene->car.position.x;
    n = x + (scene->car.speed.x * time);


    /* Only 40° allowed for wheel rotation */
    scene->car.around_tire += speed * 20;
    
    if(scene->car.around_tire > 40)
        scene->car.around_tire = 40;

    if(scene->car.around_tire < -40)
        scene->car.around_tire = -40;



    /* Wheel rotation if the car is moving forward */
    r = 0.8;    /* Wheel radius */
    i = n - x;
    j = (i * 180) / (r * 3.14);
    scene->car.rotate_tire += j;


    /* Car turning */
    if(scene->car.speed.x == -1){
        around = scene->car.around_tire;
    }
    else if(scene->car.speed.x == 1){
        around = scene->car.around_tire * -1;
    }

    beta = scene->car.rotate_car;               /* Car turning's degree */         
    beta += around / 25;                         /* Car full turning's degree /  rotation's deceleration: 25 */

    alpha = 90 - beta;                          /* The Opposite angle of the angle of rotation */
    c = scene->car.speed.x * time;              /* The car's forward movement */
    a = sin(degree_to_radian(alpha)) * c;       /* The x direction displacement from the calculated progress */
    b = cos(degree_to_radian(alpha)) * c;       /* The x direction displacement from the calculated progress */

    scene->car.position.x += a;                 
    scene->car.position.y += b;

    /* The wheel will only rotate if the car is moving */
    if(scene->car.speed.x != 0)
        scene->car.rotate_car = beta;



    /* Switching on or off the lamp */
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


    /* SUN */
    scene->sun_brightness += scene->sun_brightness_inc * time;

    if(scene->sun_brightness > 255.0){
        scene->sun_brightness = 255.0;
    }
    if(scene->sun_brightness < 0.0){
        scene->sun_brightness = 0.0;
    }

    /* CHAIR */

    scene->rocking_chair.furniture_rocking += time * scene->rocking_chair.furniture_rocking_direction * 2;

    if(scene->rocking_chair.furniture_rocking >= 10.0){
        scene->rocking_chair.furniture_rocking_direction = -1.0;
    }else if(scene->rocking_chair.furniture_rocking <= -10.0){
        scene->rocking_chair.furniture_rocking_direction = 1.0;
    }

}

void set_lighting(const Scene* scene)
{
    float b;
    b = scene->sun_brightness / 255.0;

    float ambient_light[] = { b, b, b, b };
    float diffuse_light[] = { b, b, b, b };
    float specular_light[] = { b, b, b, b };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_sun_brightness_inc(Scene* scene, float b)
{
    scene->sun_brightness_inc = b;
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
    scene->car.speedz = y;
}

void draw_car(const Scene* scene)
{
float x, y, z;
    x = scene->car.position.x;
    y = scene->car.position.y;
    z = scene->car.position.z + 0.65;

    glPushMatrix();
    
    /* Position */
    glTranslatef(x, y, z);

    /* Car turning */
    glRotatef(scene->car.rotate_car, 0.0, 0.0, 1.0);

    /* Glass */
    glPushMatrix();
        glDepthMask(GL_FALSE);
        glEnable(GL_BLEND);
        glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

        set_material(&(scene->car.material_car_glass));

        //if (scene->car.carview == NORMALW)
            draw_model(&(scene->car.glass));

        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
    glPopMatrix();

    /* Car's lamp */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 0);
        set_material(&(scene->car.material_car_lamp));
        glTranslatef(-0.001, 0.0, 0.0);
        draw_model(&(scene->car.lamp));

        /* Left side lamp's light */
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

        /* Right side lamp's light */
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

    /* Car's body */
    glPushMatrix();
        set_material(&(scene->car.material_car_body));
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_body_id);
        draw_model(&(scene->car.body));
    glPopMatrix(); 

    /* Right back wheel */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glTranslatef(0, 0.55, -0.3);
        /* Wheel's rotation */
        glRotatef(scene->car.rotate_tire, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_back));
    glPopMatrix();

    /* Left back wheel */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glRotated(180, 0.0, 0.0, 1.0);
        glTranslatef(0, 0.55, -0.3);
        /* Wheel's rotation */
        glRotatef(-scene->car.rotate_tire, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_back));
    glPopMatrix();

    /* Right front wheel */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glTranslatef(-2.36, 0.6, -0.32);
        /* Wheel turning */
        glRotatef(scene->car.around_tire, 0.0, 0.0, 1.0);
        /* Wheel's rotation */
        glRotatef(scene->car.rotate_tire, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_front));
    glPopMatrix();

    /* Left front wheel */
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, scene->car.texture_tire_id);
        glRotated(180, 0.0, 0.0, 1.0);
        glTranslatef(2.36, 0.6, -0.32);
        /* Wheel turning */
        glRotatef(scene->car.around_tire, 0.0, 0.0, 1.0);
        /* Wheel's rotation */
        glRotatef(-scene->car.rotate_tire, 0.0, 1.0, 0.0);
        draw_model(&(scene->car.tire_front));
    glPopMatrix();

    glPopMatrix();
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

void draw_tree(const Scene* scene, float x, float y, float z)
{


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, 0);
    glTranslatef(x, y, z);
    glScalef(0.5, 0.5, 0.5);

    /* TRUNK */
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    set_material(&(scene->tree.material_trunk));
    draw_model(&(scene->tree.trunk));
    glPopMatrix();

    /* LEAVES */
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    set_material(&(scene->tree.material_leaves));
    draw_model(&(scene->tree.leaves));
    glPopMatrix();

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


    /* TABLE */
    draw_table(scene, 0.0, 0.0, 0.2, 0.0);

    /* ROCKINGCHAIR */
    draw_rocking_chair(scene, 55.0, -55.0, 18.0, -135);

    /* CHAIRS */
    draw_chair(scene, -0.6, 0.0, 0.4, 0.0);
    draw_chair(scene, 0.0, -0.6, 0.4, 90.0);
    draw_chair(scene, 0.0, 0.6, 0.4, -90.0);
    draw_chair(scene, 0.6, 0.0, 0.4, 180.0);

    /* DRESSER */
    draw_dresser(scene, -3.4, 0.0, 0.4, 0.0);


    /*FENCES*/
    draw_fence(&(scene->house.fence));

    glPopMatrix();
}

void draw_house2(const Scene* scene,  float x, float y, float z)
{
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

void draw_rocking_chair(const Scene* scene,  float x, float y, float z, float degree)
{
    float rotation = scene->rocking_chair.furniture_rocking;

    glPushMatrix();
    glScalef(0.05, 0.05, 0.05);
    glTranslatef(x, y, z);

    glPushMatrix();

    glRotatef(degree, 0.0, 0.0, 1.0);
    glRotatef(rotation, 1.0, 0.0, 0.0);
    printf("%f\n", rotation);
    glBindTexture(GL_TEXTURE_2D, scene->rocking_chair.texture_id);
    draw_model(&(scene->rocking_chair.model));

    glPopMatrix();

    glPopMatrix();
}

void draw_chair(const Scene* scene,  float x, float y, float z, float degree)
{
    glPushMatrix();
    glTranslatef(x, y, z);

    glPushMatrix();

    glRotatef(degree, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->chair.texture_id);
    draw_model(&(scene->chair.model));

    glPopMatrix();

    glPopMatrix();
}

void draw_table(const Scene* scene,  float x, float y, float z, float degree)
{
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(x, y, z);

    glPushMatrix();

    glRotatef(degree, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->table.texture_id);
    draw_model(&(scene->table.model));

    glPopMatrix();

    glPopMatrix();
}

void draw_dresser(const Scene* scene,  float x, float y, float z, float degree)
{
    glPushMatrix();
    glScalef(1.0, 1.0, 1.0);
    glTranslatef(x, y, z);

    glPushMatrix();

    glRotatef(degree, 0.0, 0.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, scene->dresser.texture_id);
    draw_model(&(scene->dresser.model));

    glPopMatrix();

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

    /*TREES*/
    //draw_tree(scene, -20.0, 20.0, 0.0);
    
}

void draw_scene(const Scene* scene)
{
    set_lighting(scene);
    draw_origin();
    
    /* The city */
    draw_thecity(scene);

    /* The car */
    glPushMatrix();
    glTranslatef(17.0, 20.0, 0.0);
    draw_car(scene);
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
