#ifndef SCENE_H_
#define SCENE_H_

#include "ray.h"
#include <vector>

class RGBColor;
class LightSource;
class Object;

class Scene {
	public:
		typedef std::vector<Object*> ObjectStorage;
		typedef std::vector<LightSource*> LightStorage;
		typedef ObjectStorage::const_iterator ObjectIter;
		typedef LightStorage::const_iterator LightIter;

		virtual ~Scene();

	public:
		virtual RGBColor cast_ray(Ray const& r) const = 0;
		void push_obj(Object* obj) { objects_.push_back(obj); }
		void push_light(LightSource* light) { lights_.push_back(light); }

	public:
		ObjectIter obj_begin() 	const { return objects_.begin(); }
		ObjectIter obj_end() 	const { return objects_.end(); }
		LightIter light_begin() const { return lights_.begin(); }
		LightIter light_end() 	const { return lights_.end(); }

	private:
		//TODO:these need to be actually defined and push stuff need to be implemented
		//simple_scene covers these by only assuming sphere/phong point lights
		ObjectStorage objects_;
		LightStorage lights_;
};

#endif /* SCENE_H_ */

