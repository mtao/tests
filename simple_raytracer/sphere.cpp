#include "sphere.h"
#include "ray.h"
#include "math.h"
#include "material.h"

double Sphere::sphere_intersect(Ray const& r) const {
	//More numerical accuracy if the factors of 2 are removed
	//A2 denotes the value of A/2
	//<d,d>x^2 + 2<r,d>x + <p,p>=1
	//Ax^2 + Bx + C=0
	double A = r.dir.dot(r.dir);
	double B2 = r.start.pos.dot(r.dir);
	double C = r.start.pos.dot(r.start.pos) - radius_;
	//D=4b^2 - 4ac
	int D4 = B2 * B2 - A * C;
	if (D4 < 0) {
		return -1;
	} else {
		//need to return a positive distance
		if (B2 >= 0 && -B2 > D4) {
			return -(B2 + ::sqrt(D4)) / A;
		}
		else if (B2 > D4) {
			return -(B2 - ::sqrt(D4)) / A;
		}
		else {
			return 0;
		}
	}
}



Sphere::Sphere(Coord p, Material& m) :
	pos_(p),
	radius_(1),
	mat_(m) {
}

Sphere::Sphere(Coord pos, double radius, Material& mat) :
	pos_(pos),
	radius_(radius),
	mat_(mat) {

}

double Sphere::does_intersect(Ray const& r) const {
	return sphere_intersect(r);
}

//TODO intersect should just pass material + normal information back?
RGBColor Sphere::intersect(Ray const& r, unsigned int bounces_left) const {
	double lambda = sphere_intersect(r);
	Vector3d pos = r.start.pos + lambda * r.dir;
	if (bounces_left <= 0) {
		Ray incident = {Coord(pos), pos};
		return mat_.intersect(r, incident);
	} else {
		//TODO: add support for moving around scene?
		return intersect(r, 0);
	}
}

