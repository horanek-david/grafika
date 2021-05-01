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
    float rotate_tire;  
    float around_tire;  
    float rotate_car; 
    float speedz;  
} Car;

typedef struct Soil
{
    Material material;
    GLuint texture_id;
} Soil;

typedef struct Tree
{
    Model leaves;
    Model trunk;
    Material material_leaves;
    Material material_trunk;
} Tree;

typedef struct Railing
{
    Model model;
    Material material;
    GLuint texture_id;
} Railing;

typedef struct House
{
    Model model;
    Material material;
    GLuint texture_id;
    Railing fence;
} House;

typedef struct Furnitures
{
    Model model;
    Material material;
    GLuint texture_id;
    float furniture_rocking;
    float furniture_rocking_direction;
} Furnitures;

typedef struct Streetlight
{
    Model streetlight_pole;
    Model streetlight_glass;
    Material material_streetlight_pole;
    Material material_streetlight_glass;
} Streetlight;


typedef struct Scene
{
    Car car;
    Soil soil;
    Soil road;
    Tree tree;
    House house;
    House house2;
    House house3;
    Furnitures rocking_chair;
    Furnitures chair;
    Furnitures table;
    Furnitures dresser;
    Streetlight lamp;
    Railing barrier;
    float sun_brightness;
    float sun_brightness_inc;

} Scene;

/**
 * Initialize the soil by loading textures.
 */
void init_soil(Scene* scene);

/**
 * Initialize the tree by loading textures.
 */
void init_tree(Scene* scene);

/**
 * Initialize the road by loading models.
 */
void init_road(Scene* scene);

/**
 * Initialize the main house by loading models and textures.
 */
void init_mainhouse(Scene* scene);

/**
 * Initialize the houses next to the main house by loading models and textures.
 */
void init_house2(Scene* scene);

/**
 * Initialize the big house in front of the main house by loading models and textures.
 */
void init_house3(Scene* scene);

/**
 * Initialize the fence around the houses by loading models and textures.
 */
void init_fence(Railing* fence);

/**
 * Initialize the barrier around the city by loading models and textures.
 */
void init_barrier(Scene* scene);

/**
 * Initialize the car by loading models.
 */
void init_car(Scene* scene);

/**
 * Initialize a chair by loading models.
 */
void init_rocking_chair(Scene* scene);

/**
 * Initialize a chair by loading models.
 */
void init_chair(Scene* scene);

/**
 * Initialize a table by loading models.
 */
void init_table(Scene* scene);

/**
 * Initialize a dresser by loading models.
 */
void init_dresser(Scene* scene);

/**
 * Initialize a streetlight by loading models.
 */
void draw_streetlight(const Scene* scene, GLenum light, float x, float y, float z, float degree);

/**
 * Initialize a streetlight by loading models.
 */
void init_streetlight(Scene* scene);

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Update scene
 */
void update_scene(Scene* scene, Camera* camera, double time);

/**
 * Set the lighting of the scene.
 */
void set_lighting(const Scene* scene);

/**
 * Set the sun brightness
 */
void set_sun_brightness_inc(Scene* scene, float b);

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Set the lighting of the left car lamp.
 */
void set_car_lamp_l(float x, float y, float z);

/**
 * Set the lighting of the right car lamp.
 */
void set_car_lamp_r(float x, float y, float z);

/**
 * Set the lighting of street lamp.
 */
void set_streetlight(GLenum light);

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
 * Draw a grass under the houses.
 */
void draw_grass(const Scene* scene, float x, float y, float z);

/**
 * Draw a grass behind the front and back road.
 */
void draw_grass2(const Scene* scene, float x, float y, float z);

/**
 * Draw a grass next to the side roads.
 */
void draw_grass3(const Scene* scene, float x, float y, float z);

/**
 * Draw a road in front of the houses and also behind them.
 */
void draw_road(const Scene* scene, float x, float y, float z);

/**
 * Draw the side roads.
 */
void draw_road2(const Scene* scene, float x, float y, float z);

/**
 * Draw a tree.
 */
void draw_tree(const Scene* scene, float x, float y, float z);

/**
 * Draw the main house.
 */
void draw_mainhouse(const Scene* scene, float x, float y, float z);

/**
 * Draw the second house.
 */
void draw_house2(const Scene* scene, float x, float y, float z);

/**
 * Draw the big house.
 */
void draw_house3(const Scene* scene, float x, float y, float z);

/**
 * Draw a fence around the small house.
 */
void draw_fence(const Railing* fence);

/**
 * Draw a fence around the big house.
 */
void draw_fence2(const Railing* fence);

/**
 * Draw a barrier around the city.
 */
void draw_barrier(const Scene* scene);

/**
 * Draw a rocking chair.
 */
void draw_rocking_chair(const Scene* scene,  float x, float y, float z, float degree);

/**
 * Draw a normal chair.
 */
void draw_chair(const Scene* scene,  float x, float y, float z, float degree);

/**
 * Draw a table.
 */
void draw_table(const Scene* scene,  float x, float y, float z, float degree);

/**
 * Draw a dresser.
 */
void draw_dresser(const Scene* scene,  float x, float y, float z, float degree);

/**
 * Draw the city.
 */
void draw_thecity(const Scene* scene);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
