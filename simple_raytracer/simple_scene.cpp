#include "simple_scene.h"
#include "object.h"
using namespace std;
RGBColor SimpleScene::cast_ray(Ray const& ray) const {
	double minlambda = -1.0;
	double newlambda=-1.0;

	ObjectIter closest = obj_end();
	for(ObjectIter i = obj_begin(); i != obj_end(); ++i) {
		newlambda = (*i)->intersect_lambda(ray);
		cout << minlambda << ","<< newlambda << endl;
		if (minlambda != -1.0 || (newlambda > 0 && minlambda > newlambda)) {
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

