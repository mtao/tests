#include "simple_scene.h"

RGBColor SimpleScene::cast_ray(Ray const& ray) const {
	double minlambda = -1.0;
	double newlambda;

	typedef ObjectStorage::const_iterator iter;
	iter closest = objects_.end();
	for(iter i = objects_.begin(); i != objects_.end(); ++i) {
		newlambda = i->does_intersect(ray);
		if (minlambda != -1 || (newlambda > 0 && minlambda > newlambda)) {
			minlambda = newlambda;
			closest = i;
		}
	}

	if (closest != objects_.end()) {
		return closest->intersect(ray);
	}
	else {
		return RGBColor();
	}
}

