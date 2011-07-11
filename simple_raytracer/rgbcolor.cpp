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

inline unsigned int scaleTo255(double d) {
	return static_cast<unsigned int>(d * 255.0);
}


unsigned int toUint(RGBColor const& rgb) {
	unsigned int result = 0xff000000 | (scaleTo255(rgb[0]) << 16)
									 | (scaleTo255(rgb[1]) << 8)
									 | scaleTo255(rgb[2]);

	return result;
}

}
