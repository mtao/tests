#include <Eigen/Core>
#include "color.h"

class RGBColor: public Color {

	public:
		RGBColor(unsigned int r, unsigned int g, unsigned int b);
		RGBColor(double r, double g, double b);
		RGBColor(Array<double,3,1> rgb);
		double r() {return rgb_[0];}
		double g() {return rgb_[1];}
		double b() {return rgb_[2];}
		void truncate();

	private:
		Array<double,3,1> rgb_;

};
