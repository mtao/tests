#include "phong_point_light.h"
#include "ray.h"
#include "material.h"
#include "math.h"

PhongPointLight::PhongPointLight(Coord pos,
                                 RGBColor const& ambient,
                                 RGBColor const& diffuse,
                                 RGBColor const& specular) :
	pos_(pos),
	ambient_(ambient),
	diffuse_(diffuse),
	specular_(specular) {

}


RGBColor PhongPointLight::shade(Ray const& ray, Ray const& incident, Material const& mat) const {
	Vector3d ray_dir = ray.dir.normalized(); // faces into the object
	Vector3d normal = incident.dir.normalized();
	Vector3d light_dir = (pos_.pos - incident.start.pos).normalized(); // from point to light source

	/*
	 * This stuff has to be part of material's intersect...
	 */
	double incident_angle = ray_dir.dot(normal);
	double reflected_angle_diff = ray_dir.dot(2 * (normal.dot(light_dir) * normal - light_dir));
	return mat.ambient() * ambient_
	       + incident_angle * (diffuse_ * mat.diffuse())
	       + ::pow(reflected_angle_diff, mat.specular_pow()) * mat.specular() * specular_;
}
