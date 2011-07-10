#include "phong_material.h"
#include "scene.h"
#include "rgbcolor.h"
#include "light_source.h"

PhongMaterial::PhongMaterial(Scene& scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow) :
	Material(scene),
	ambient_(ambient),
	diffuse_(diffuse),
	specular_(specular),
	specular_pow_(specular_pow),
	translucent_(0) {

}

PhongMaterial::PhongMaterial(Scene& scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow, bool translucent) :
	Material(scene),
	ambient_(ambient),
	diffuse_(diffuse),
	specular_(specular),
	specular_pow_(specular_pow),
	translucent_(translucent) {

}

RGBColor PhongMaterial::intersect(Ray const& r, Ray const& incident) const {
	RGBColor col(ColorOps::black);

	for(Scene::LightIter l = scene().light_begin(); l != scene().light_end(); ++l) {
		col += (*l)->shade(r, incident, *this);
	}

	ColorOps::clamp(col);
	return col;
}
