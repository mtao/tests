#ifndef SPHERE_H_
#define SPHERE_H_

#include "object.h"
#include "rgbcolor.h"
#include "coord.h"

class Sphere : public Object {

	public:
		Sphere(Coord pos, Material& mat);
		Sphere(Coord pos, double radius);
		Sphere(Coord pos, double radius, Material& mat);
		RGBColor intersect(Ray& r, unsigned int bounces_left = 0);
		double does_intersect(Ray r);
		double radius() { return radius_; }
		Coord pos() { return pos_; }

	private:
		double radius_;
		double sphere_intersect(Ray& r);

		Coord pos_;
		Material& mat_;

};


#endif /* SPHERE_H_ */

