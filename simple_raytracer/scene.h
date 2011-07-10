#ifndef SCENE_H_
#define SCENE_H_

#include "ray.h"
#include <vector>

class RGBColor;
class LightSource;
class Object;

class Scene {

	public:
		virtual ~Scene();

	public:
		virtual RGBColor cast_ray(Ray const& r) = 0;
		virtual void push_obj(Object* o) = 0;
		virtual void push_light(LightSource* l) = 0;
	private:
		//TODO:these need to be actually defined and push stuff need to be implemented
		//simple_scene covers these by only assuming sphere/phong point lights
};

#endif /* SCENE_H_ */

