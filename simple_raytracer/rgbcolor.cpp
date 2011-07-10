#include "rgbcolor.h"

RGBColor::RGBColor() :
		rgb_(0.0, 0.0, 0.0) {

}

RGBColor::RGBColor(double r, double g, double b) :
		rgb_(r, g, b) {

}

RGBColor::RGBColor(unsigned int r, unsigned int g, unsigned int b) :
		rgb_(r/255.0, g/255.0, b/255.0) {

}

//RGBColor& RGBColor::operator +(RGBColor x, RGBColor y){
//	return RGBColor(x.rgb_ + y.rgb);
//}
//
//RGBColor& RGBColor::operator *(RGBColor x, RGBColor y){
//	return RGBColor(x.rgb_ * y.rgb);
//}
//
//RGBColor& RGBColor::operator *(double c, RGBColor x){
//	return RGBColor(c * x.rgb_);
//}
//
//RGBColor& RGBColor::operator *(RGBColor x, double c){
//	return RGBColor(x.rgb_ * c);
//}

void RGBColor::clamp() {
	if (rgb_[0] > 1.0) { rgb[0] = 1.0; }
	if (rgb_[1] > 1.0) { rgb[1] = 1.0; }
	if (rgb_[2] > 1.0) {rgb[2] = 1.0; }
	if (rgb_[0] < 0) { rgb[0] = 0.0; }
	if (rgb_[1] < 0) { rgb[1] = 0.0; }
	if (rgb_[2] < 0) { rgb[2] = 0.0; }
}
