#include "rgbcolor.h"
#include "intersection.h"

class LightSource {

	public:
		virtual RGBColor shade(Intersection i);
		
};
