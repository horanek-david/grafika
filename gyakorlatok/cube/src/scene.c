#include "scene.h"

#include <GL/glut.h>

#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->rotation = 0.0;

    load_model(&(scene->cube), "porsche.obj");
    load_model(&(scene->cat), "cat.obj");

    /*
    scene->texture_id = load_texture("cube.png"); 
    */

    glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    // Light
    scene->light.ambient.red = 1.0f;
    scene->light.ambient.green = 1.0f;
    scene->light.ambient.blue = 1.0f;

    scene->light.diffuse.red = 1.0f;
    scene->light.diffuse.green = 1.0f;
    scene->light.diffuse.blue = 1.0f;

    scene->light.specular.red = 1.0f;
    scene->light.specular.green = 1.0f;
    scene->light.specular.blue = 1.0f;

    scene->light.position.x = 0.0;
    scene->light.position.y = 0.0;
    scene->light.position.z = 10.0;

    scene->light.speed.x = 0.0;
    scene->light.speed.y = 0.0;
    scene->light.speed.z = 0.0;

    scene->light.brightness = 255;
    scene->light.bspeed = -1;

    // Black
    scene->material.ambient.red = 0.25f;
    scene->material.ambient.green = 0.25f;
    scene->material.ambient.blue = 0.25f;

    scene->material.diffuse.red = 0.4f;
    scene->material.diffuse.green = 0.4f;
    scene->material.diffuse.blue = 0.4f;

    scene->material.specular.red = 0.774597f;
    scene->material.specular.green = 0.774597f;
    scene->material.specular.blue = 0.774597f;

    scene->material.shininess = 76.8;

    // Plastic
    scene->plastic_material.ambient.red = 0.0f;
    scene->plastic_material.ambient.green = 0.0f;
    scene->plastic_material.ambient.blue = 0.0f;

    scene->plastic_material.diffuse.red = 0.1f;
    scene->plastic_material.diffuse.green = 0.1f;
    scene->plastic_material.diffuse.blue = 0.1f;

    scene->plastic_material.specular.red = 0.5f;
    scene->plastic_material.specular.green = 0.5f;
    scene->plastic_material.specular.blue = 0.5f;

    scene->plastic_material.shininess = 32.0;

    // Gold
    scene->gold_material.ambient.red = 0.24725f;
    scene->gold_material.ambient.green = 0.1995f;
    scene->gold_material.ambient.blue = 0.0745f;

    scene->gold_material.diffuse.red = 0.75164f;
    scene->gold_material.diffuse.green = 0.60648f;
    scene->gold_material.diffuse.blue = 0.22648f;

    scene->gold_material.specular.red = 0.628281f;
    scene->gold_material.specular.green = 0.555802f;
    scene->gold_material.specular.blue = 0.366065f;

    scene->gold_material.shininess = 51.2;
}

void set_lighting(const Light* light)
{
    float ambient_light[] = {
        light->ambient.red,
        light->ambient.green,
        light->ambient.blue,
        1.0f
    };

    float diffuse_light[] = {
        light->diffuse.red,
        light->diffuse.green,
        light->diffuse.blue,
        1.0f
    };

    float specular_light[] = {
        light->specular.red,
        light->specular.green,
        light->specular.blue,
        1.0f
    };

    float position[] = {
        light->position.x,
        light->position.y,
        light->position.z,
        1.0f
    };

    /*
    float ambient_light[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    float diffuse_light[] = { 0.3f, 0.3f, 0.3, 1.0f };
    float specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };
    */

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

void update_scene(Scene* scene, double time)
{
    scene->rotation += 10 * time;
    scene->light.position.x += scene->light.speed.x * time * 2;
    scene->light.position.y += scene->light.speed.y * time * 2;
    scene->light.position.z += scene->light.speed.z * time * 2;

    if(scene->light.brightness > 255){
        scene->light.bspeed = -1;
    }

    if(scene->light.brightness < 0){
        scene->light.bspeed = 1;
    }
    
    scene->light.brightness += scene->light.bspeed / 2;
    scene->light.diffuse.red = scene->light.brightness / 255.0;
    scene->light.diffuse.green = scene->light.brightness / 255.0;
    scene->light.diffuse.blue = scene->light.brightness / 255.0;
}

void set_light_speed(Scene* scene, float x)
{
    scene->light.speed.x = x;
}

void set_light_side_speed(Scene* scene, float y)
{
    scene->light.speed.x = y;
}

void set_light_lift_speed(Scene* scene, float z)
{
    scene->light.speed.x = z;
}

void set_brightness(Scene* scene, float brightness)
{
    scene->light.brightness += brightness;
    if(scene->light.brightness > 255){
        scene->light.brightness = 255;
    }
    else if(scene->light.brightness < 0){
        scene->light.brightness = 0;
    }

    scene->light.diffuse.red = scene->light.brightness / 255.0;
    scene->light.diffuse.green = scene->light.brightness / 255.0;
    scene->light.diffuse.blue = scene->light.brightness / 255.0;

}

void draw_scene(const Scene* scene)
{ 
    set_lighting(&(scene->light));
    draw_origin();

    set_material(&(scene->material));
    draw_cat(scene);
    draw_porsche(scene);
    draw_pot(scene);
}

void draw_cat(const Scene* scene){
    glPushMatrix();
    glTranslatef(2, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glScalef(0.6, 0.6, 0.6);
    set_material(&(scene->plastic_material));
    draw_model(&(scene->cat));
    glPopMatrix();
}

void draw_porsche(const Scene* scene){
    glPushMatrix();
    glTranslatef(0, 0, 0.8);
    glScalef(1.5, 1.5, 1.5);
    glRotatef(90, 1, 0, 0);
    set_material(&(scene->gold_material));
    draw_model(&(scene->cube));
    glPopMatrix();
}

void draw_pot(const Scene* scene){
    glPushMatrix();
    glTranslatef(-2, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(scene->rotation, 0, 1, 0);
    glScalef(0.3, 0.3, 0.3);
    set_material(&(scene->material));
    glutSolidTeapot(1);
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
