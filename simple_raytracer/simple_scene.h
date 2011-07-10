#ifndef SIMPLE_SCENE_H_
#define SIMPLE_SCENE_H_

#include "scene.h"
#include <vector>

class SimpleScene: public Scene {
		typedef std::vector<Object*> ObjectStorage;
		typedef std::vector<LightSource*> LightStorage;

	public:
		SimpleScene() { }

		RGBColor cast_ray(Ray const& r);
		void push_obj(Object* o);
		void push_light(LightSource* l);

	private:
		ObjectStorage objects_;
		LightStorage lights_;
};

#endif /* SIMPLE_SCENE_H_ */

