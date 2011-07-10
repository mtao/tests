#ifndef LIGHT_SOURCE_H_
#define LIGHT_SOURCE_H_

#include "rgbcolor.h"
class Material;
class Ray;

class LightSource {

	public:
		virtual RGBColor shade(Ray const& ray, Ray const& incident, Material const& mat) const = 0;
		
};


#endif /* LIGHT_SOURCE_H_ */

