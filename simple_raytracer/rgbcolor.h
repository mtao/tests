#ifndef RGBCOLOR_H_
#define RGBCOLOR_H_

#include <Eigen/Core>
using Eigen::Array;

/*
 * Concern, might not be able to leverage Eigen's expression templates
 * if we wrap the type.
 * Perhaps better to typedef, and have static functions for extra
 * functionality.
 * Could consider later if performance is needed
 */

typedef Array<double,3,1> RGBColor;

namespace ColorOps {
	const RGBColor black(0.0, 0.0, 0.0);
	const RGBColor white(1.0, 1.0, 1.0);
	void clamp(RGBColor& rgb);
	unsigned int toUint(RGBColor const&);
}

//class RGBColor {
//
//public:
//	RGBColor(); ///< black
//	RGBColor(double r, double g, double b);
//	RGBColor(unsigned int r, unsigned int g, unsigned int b);
//	RGBColor(Array<double,3,1> rgb) : rgb_(rgb) { }
//
//	double r() { return rgb_[0]; }
//	double g() { return rgb_[1]; }
//	double b() { return rgb_[2]; }
//	void clamp();
//
//
//	// compound assignment operators
//	RGBColor& operator +=(RGBColor const& other) {
//		rgb_ += other.rgb_;
//		return *this;
//	}
//
//	RGBColor& operator *=(RGBColor const& other) {
//		rgb_ *= other.rgb_;
//		return *this;
//	}
//
//	RGBColor& operator *=(double const c) {
//		rgb_ *= c;
//		return *this;
//	}
//
//	// binary operators
//	RGBColor const operator +(RGBColor const& other) {
//		return RGBColor(*this) += other;
//	}
//
//	RGBColor const operator *(RGBColor const& other){
//		return RGBColor(*this) += other;
//	}
//
//	RGBColor const operator *(double c) {
//		return RGBColor(*this) *= c;
//	}
//
//private:
//	Array<double,3,1> rgb_;
//
//};


#endif /* RGBCOLOR_H_ */


