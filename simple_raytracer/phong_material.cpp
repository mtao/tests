#include "scene.h"
#include "RGBColor.h"
PhongMaterial::PhongMaterial(Scene* scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow){
	ambient_=ambient;
	diffuse_=diffuse;
	specular_=specular;
	specular_pow_=specular_pow;
	translucent_=0;
	scene_=scene;

}

PhongMaterial::PhongMaterial(Scene* scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow, bool translucent){
	ambient_=ambient;
	diffuse_=diffuse;
	specular_=specular;
	specular_pow_=specular_pow;
	translucent_=translucent;
	scene_=scene;

}

RGBColor PhongMaterial::intersect(Ray& r, Ray& incident){
	vector<PhongLight> lights = scene->lights();
	unsigned int num_lights = lights->size();
	RGBColor col(0.0,0.0,0.0);
	for(i=0, i < num_lights; i++){
		col+=lights[i].shade(r,incident,this);
	}
	col.clamp();

		
}
