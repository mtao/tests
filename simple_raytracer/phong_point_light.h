#ifndef PHONG_POINT_LIGHT_H_
#define PHONG_POINT_LIGHT_H_

#include "light_source.h"
#include "rgbcolor.h"
#include "coord.h"
class Ray;
class Material;

class PhongPointLight: public LightSource {
	public:
		PhongPointLight(Coord pos, RGBColor ambient, RGBColor diffuse, RGBColor specular);
		RGBColor shade(Ray const& ray, Ray const& incident, Material const& mat) const;
		
	private:
		Coord pos_;
		RGBColor ambient_, diffuse_, specular_;

};


#endif /* PHONG_POINT_LIGHT_H_ */

