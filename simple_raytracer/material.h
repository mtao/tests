#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "rgbcolor.h"
#include "scene.h"

class Material {
	public:
		Material(Scene& scene) : scene_(scene) { }
		virtual ~Material();

	public:
		virtual RGBColor intersect(Ray const& ray, Ray const& incident) const = 0;
		virtual RGBColor ambient() const = 0;
		virtual RGBColor diffuse() const = 0;
		virtual RGBColor specular() const = 0;
		virtual double specular_pow() const = 0;

		Scene& scene() { return scene_; }
		Scene const& scene() const { return scene_; }

	private:
		Scene& scene_;
};


#endif /* MATERIAL_H_ */

