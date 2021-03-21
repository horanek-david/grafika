#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model cat;
    Material material;
    Material plastic_material;
    Material gold_material;
    Light light;
    GLuint texture_id;
    float rotation;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting(const Light* light);

/**
 * Set the current material.
 */
void set_material(const Material* material);

void update_scene(Scene* scene, double time);

/**
 * Set the light speed.
 */
void set_light_speed(Scene* scene, float x);

/**
 * Set the side light speed.
 */
void set_light_side_speed(Scene* scene, float y);

/**
 * Set the light lift speed.
 */
void set_light_lift_speed(Scene* scene, float z);

/**
 * Set the brightness.
 */
void set_brightness(Scene* scene, float brightness);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw a cat.
 */
void draw_cat(const Scene* scene);

/**
 * Draw a porsche.
 */
void draw_porsche(const Scene* scene);

/**
 * Draw a pot.
 */
void draw_pot(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
