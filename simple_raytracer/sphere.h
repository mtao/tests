#ifndef SPHERE_H_
#define SPHERE_H_

#include "object.h"
#include "rgbcolor.h"
#include "coord.h"

class Material;

class Sphere : public Object {

	public:
		Sphere(Coord pos, Material& mat);
		Sphere(Coord pos, double radius);
		Sphere(Coord pos, double radius, Material& mat);
		RGBColor intersect(Ray const& r, unsigned int bounces_left) const;
		double does_intersect(Ray const& r) const;
		double radius() { return radius_; }
		Coord pos() const { return pos_; }

	private:
		Coord pos_;
		double radius_;
		double sphere_intersect(Ray const& r) const;
		Material& mat_;

};


#endif /* SPHERE_H_ */

