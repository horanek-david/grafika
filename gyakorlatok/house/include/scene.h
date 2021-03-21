#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "utils.h"

#include <obj/load.h>

typedef struct Scene
{
    Model house_model;
    Model cube_model;
    Model kocka_model;
    float rotate_speed;
    vec3 position;
    vec3 position_speed;
} Scene;

/**
 * Initialize the scene by loading model.
 */
void init_scene(Scene* scene);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw a house.
 */
void draw_house(const Scene* scene);

/**
 * Draw a cube.
 */
void draw_kocka(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Set the speed.
 */
void set_speed(Scene* scene, float speed);

/**
 * Set the side speed.
 */
void set_side_speed(Scene* scene, float speed);

/**
 * Set the lift speed.
 */
void set_lift_speed(Scene* scene, float speed);


#endif /* SCENE_H */
