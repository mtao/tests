#include "triangle.h"
#include "ray.h"
#include "math.h"
#include "material.h"
#include <iostream>

using namespace std;

double Triangle::intersect_lambda(Ray const& r) const {
	cout << "intersection";
	double lambda=-normal_.dot(r.start.pos)/normal_.dot(r.dir);
	Vector3d pos=r.start.pos + lambda * r.dir;
	if(
			(v2_-v1_).dot(pos-v1_)>=0 &&
			(v3_-v2_).dot(pos-v2_)>=0 &&
			(v1_-v3_).dot(pos-v3_)>=0
			)
	{
		return lambda;
	} else {
		return -1;
	}


}


Ray Triangle::incident(Vector3d const& pos) const {
	return Ray(pos, normal_);
}

