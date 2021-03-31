#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Model hare;
    Material material;
    GLuint cube_texture_id;
    GLuint hare_texture_id;
    GLuint chess_texture_id;
    GLuint chesstable_texture_id;
    GLuint colored_texture_id;
    double w;
    double s;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);


void update_scene(Scene* scene, double time);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draw a cube.
 */
void draw_cube(const Scene* scene);

/**
 * Draw a rabbit.
 */
void draw_hare(const Scene* scene);

/**
 * Draw a picture thats moving.
 */
void draw_moving_picture(const Scene* scene);

/**
 * Draw a chesstable.
 */
void draw_chesstable1(const Scene* scene);

/**
 * Draw a chesstable.
 */
void draw_chesstable2(const Scene* scene);

/**
 * Draw a colored picture.
 */
void draw_colored(const Scene* scene);

#endif /* SCENE_H */
