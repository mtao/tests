#include "rgbcolor.h"


namespace ColorOps {

void clamp(RGBColor& rgb) {
	if (rgb[0] > 1.0) { rgb[0] = 1.0; }
	if (rgb[1] > 1.0) { rgb[1] = 1.0; }
	if (rgb[2] > 1.0) {rgb[2] = 1.0; }
	if (rgb[0] < 0) { rgb[0] = 0.0; }
	if (rgb[1] < 0) { rgb[1] = 0.0; }
	if (rgb[2] < 0) { rgb[2] = 0.0; }
}

}
