#include "plane.h"
#include "ray.h"
#include "material.h"
#include <iostream>

using namespace std;


double Plane::intersect_lambda(Ray const& r) const {
    double result = (-n_.dot(r.start.pos))/n_.dot(r.dir);
    cout << "trying to intersect with plane " << result << " denom " << n_.dot(r.dir) << endl;
    return result;
}


Ray Plane::incident(Vector3d const& pos) const {
    return Ray(pos, n_);
}

