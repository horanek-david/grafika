#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Soil
{
    Material material;
    GLuint texture_id;
} Soil;

typedef struct House
{
    Model model;
    Material material;
    GLuint texture_id;
} House;

typedef struct Scene
{
    Soil soil;
    Soil road;
    House house;
    House house2;
    House house3;
} Scene;

/**
 * Initialize the soil by loading textures.
 */
void init_soil(Scene* scene);

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
