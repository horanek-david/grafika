#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model table;
    Model chair;
    Model floor;
    Model house;
    Model house2;
    Material material;
    GLuint texture_id;
    GLuint texture_table_id;
    GLuint texture_chair_id;
    GLuint texture_floor_id;
    GLuint texture_house_id;
    GLuint texture_house2_id;
    GLuint texture_grass_id;
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
void draw_house(const Scene* scene);

/**
 * Draw the city.
 */
void draw_house2(const Scene* scene);


/**
 * Draw a block of grass.
 */
void draw_grass(const Scene* scene, float x, float y, float z);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
