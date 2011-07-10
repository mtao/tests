#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "rgbcolor.h"
#include "scene.h"

class Material {
	public:
		Material(Scene& scene) : scene_(scene) { }
		virtual ~Material();

	public:
		virtual RGBColor intersect(Ray const& ray, Ray const& incident) = 0;

		Scene& scene() { return scene_; }

	private:
		Scene& scene_;
};


#endif /* MATERIAL_H_ */

