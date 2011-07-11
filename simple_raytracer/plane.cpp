#include "plane.h"
#include "ray.h"
#include "math.h"
#include "material.h"


using namespace std;


double Plane::intersect_lambda(Ray const& r) const {
	cout << "trying to intersect with plane" << -n_.dot(r.start.pos)/n_.dot(r.dir) << endl;
	return -n_.dot(r.start.pos)/n_.dot(r.dir);


}


Ray Plane::incident(Vector3d const& pos) const {
	return Ray(pos, n_);
}

