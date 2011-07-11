/*
 * main.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: Alexander Kondratskiy
 */

#include "scene.h"
#include "phong_material.h"
#include "sphere.h"
#include "phong_point_light.h"
#include "simple_scene.h"
#include "simple_raytracer.h"
#include "array_buffer.h"

int main() {
	// need a mechanism for the scene itself
	int width = 10;//320;
	int height = 10;//240;

	SimpleScene scene;
	PhongMaterial metal(scene,
						RGBColor(0.1,0.1,0.1),
						RGBColor(0.8,0.8,0.8),
						RGBColor(0.8,0.8,0.8),
						2.0);

	Sphere sphere(Coord(0,0,4), metal);
	scene.push_obj(&sphere);

	PhongPointLight light(Coord(-1.0, -1.0, -1.0),
						  RGBColor(1.0,1.0,1.0),
						  RGBColor(1.0,1.0,1.0),
						  RGBColor(1.0,1.0,1.0));
	scene.push_light(&light);

	Coord cam(0,0,-1);
	SimpleRaytracer raytracer(scene);
	ArrayBuffer buffer(width, height);
	raytracer.render(buffer, 60, cam);
	// store rays somehow
}