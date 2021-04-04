#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Car
{
    Model body;
    Model tire_front;
    Model tire_back;
    Model glass;
    Model lamp;
    Material material_car_body;
    Material material_car_glass;
    Material material_car_lamp;
    GLuint texture_body_id;
    GLuint texture_tire_id;
    vec3 position;
    vec3 speed;
    int is_light_on;
    float rotate;
    float rotatez;
    float rotatea;
    float speedz;
    float rotcen;
} Car;

typedef struct Scene
{
    Car car;
    Model cube;
    Model table;
    Model chair;
    Model rchair;
    Model floor;
    Model house;
    Model house2;
    Model house3;
    Model fence;
    Material material;
    GLuint texture_id;
    GLuint texture_table_id;
    GLuint texture_chair_id;
    GLuint texture_rchair_id;
    GLuint texture_floor_id;
    GLuint texture_house_id;
    GLuint texture_house2_id;
    GLuint texture_house3_id;
    GLuint texture_grass_id;
    GLuint texture_road_id;
    GLuint texture_fence_id;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw a table.
 */
void draw_table(const Scene* scene, float x, float y, float z);

/**
 * Draw a rocking chair.
 */
void draw_rockingchair(const Scene* scene, float x, float y, float z, float degree);

/**
 * Draw a chair.
 */
void draw_chair(const Scene* scene, float x, float y, float z, float degree);

/**
 * Draw a floor.
 */
void draw_floor(const Scene* scene);

/**
 * Draw a house.
 */
void draw_house(const Scene* scene, float x, float y, float z);

/**
 * Draw a house2.
 */
void draw_house2(const Scene* scene, float x, float y, float z);

/**
 * Draw a house3.
 */
void draw_house3(const Scene* scene, float x, float y, float z);

/**
 * Draw a block of grass.
 */
void draw_grass(const Scene* scene, float x, float y, float z);

/**
 * Draw a block of road.
 */
void draw_road(const Scene* scene, float x, float y, float z);

/**
 * Draw a block of road.
 */
void draw_road2(const Scene* scene, float x, float y, float z);

/**
 * Draw a fence around a house.
 */
void draw_fence(const Scene* scene);

/**
 * Draw a fence around the big house.
 */
void draw_fence2(const Scene* scene);

/**
 * Draw the city.
 */
void draw_city(const Scene* scene, float x, float y, float z);




/**
 * Initialize the car by loading models.
 */
void init_car(Scene* scene);

/**
 * Update scene
 */
void update_scene(Scene* scene, double time);

/**
 * Set the lighting of the left car lamp.
 */
void set_car_lamp_l(float x, float y, float z);

/**
 * Set the lighting of the right car lamp.
 */
void set_car_lamp_r(float x, float y, float z);

/**
 * Set car speed
 */
void set_car_speed(Scene* scene, float x);

/**
 * Set car side speed
 */
void set_car_side_speed(Scene* scene, float y);

/**
 * Draw the car objects.
 */
void draw_car(const Scene* scene);




/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
