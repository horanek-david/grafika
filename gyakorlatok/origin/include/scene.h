#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
	float teapot_rotation;
	float sphere_rotation;
	int old_x;
	int old_y;
} Scene;

/**
 * Initialize the scene.
 */
void init_scene(Scene* scene);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Update the previous mouse position.
 */
void update_old(Scene* scene, int old_x, int old_y);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draw a triangle.
 */
void draw_triangle();

/**
 * Draw a sphere.
 */
void draw_sphere();

/**
 * Draw a cylinder in the coordinate system.
 */
void draw_cylinder();

/**
 * Draw a chess table.
 */
void draw_chess();

#endif /* SCENE_H */

