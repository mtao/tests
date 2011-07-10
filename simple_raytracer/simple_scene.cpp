#include "simple_scene.h"
#include "object.h"

RGBColor SimpleScene::cast_ray(Ray const& ray) const {
	double minlambda = -1.0;
	double newlambda;

	ObjectIter closest = obj_end();
	for(ObjectIter i = obj_begin(); i != obj_end(); ++i) {
		newlambda = (*i)->does_intersect(ray);
		if (minlambda != -1 || (newlambda > 0 && minlambda > newlambda)) {
			minlambda = newlambda;
			closest = i;
		}
	}

	if (closest != obj_end()) {
		return (*closest)->intersect(ray);
	}
	else {
		return ColorOps::black;
	}
}

