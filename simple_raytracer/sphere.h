#ifndef SPHERE_H_
#define SPHERE_H_

#include "object.h"
#include "rgbcolor.h"
#include "coord.h"

class Material;

class Sphere : public Object {

	public:
		Sphere(Coord const& pos, Material& mat): Object(mat), coord_(pos), radius_(1.0) { }
		Sphere(Coord const& pos, double radius, Material& mat): Object(mat), coord_(pos), radius_(radius) { }
		double intersect_lambda(Ray const& r) const;
		Ray incident(Vector3d const& pos) const;
		double radius() { return radius_; }
		Coord const& pos() const { return coord_; }

	private:
		Coord coord_;
		double radius_;
		double sphere_intersect(Ray const& r) const;

};


#endif /* SPHERE_H_ */

