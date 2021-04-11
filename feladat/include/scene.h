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

typedef struct Scene
{
    Soil soil;
    Soil road;
} Scene;

/**
 * Initialize the soil by loading models.
 */
void init_soil(Scene* scene);

/**
 * Initialize the road by loading models.
 */
void init_road(Scene* scene);

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
 * Draw a road on front of the houses and also behind them.
 */
void draw_road(const Scene* scene, float x, float y, float z);

/**
 * Draw the side roads.
 */
void draw_road2(const Scene* scene, float x, float y, float z);

/**
 * Draw the city.
 */
void draw_thecity(const Scene* scene, float x, float y, float z);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
