#ifndef LIGHT_SOURCE_H_
#define LIGHT_SOURCE_H_

#include "rgbcolor.h"
#include "intersection.h"

class LightSource {

	public:
		virtual RGBColor shade(Ray const& ray, Ray const& incident, Material& mat) = 0;
		
};


#endif /* LIGHT_SOURCE_H_ */

