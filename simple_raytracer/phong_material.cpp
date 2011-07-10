#include "phong_material.h"
#include "scene.h"
#include "rgbcolor.h"

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

RGBColor PhongMaterial::intersect(Ray const& r, Ray const& incident) {
	vector<PhongLightSource> lights = scene.lights();
	unsigned int num_lights = lights->size();
	RGBColor col(0.0,0.0,0.0);

	for(i=0; i < num_lights; i++) {
		col+=lights[i].shade(r,incident,this);
	}

	col.clamp();
		
}
