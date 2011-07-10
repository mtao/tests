#ifndef PHONG_MATERIAL_H_
#define PHONG_MATERIAL_H_

#include "material.h"

class PhongMaterial: public Material {

	public:
		PhongMaterial(Scene& scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow);
		PhongMaterial(Scene& scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow, bool translucent);

	public:
		RGBColor intersect(Ray const& r, Ray const& incident) const;
		RGBColor ambient() const { return ambient_; }
		RGBColor diffuse() const { return diffuse_; }
		RGBColor specular() const { return specular_; }
		double specular_pow() const { return specular_pow_; }

	private:
		RGBColor ambient_;
		RGBColor diffuse_;
		RGBColor specular_;
		double specular_pow_;
		bool translucent_;
};


#endif /* PHONG_MATERIAL_H_ */

