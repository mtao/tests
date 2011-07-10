#ifndef SIMPLE_SCENE_H_
#define SIMPLE_SCENE_H_

#include "scene.h"
#include <vector>

class SimpleScene: public Scene {

	public:
		SimpleScene() { }

		RGBColor cast_ray(Ray const& r) const;

	private:
};

#endif /* SIMPLE_SCENE_H_ */

