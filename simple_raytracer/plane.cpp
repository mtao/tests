#include "plane.h"
#include "ray.h"
#include "material.h"
#include <iostream>

using namespace std;


double Plane::intersect_lambda(Ray const& r) const {
//    cout << "trying to intersect with plane " << result << " denom " << n_.dot(r.dir) << endl;
    return (-n_.dot(r.start.pos))/n_.dot(r.dir);
}


Ray Plane::incident(Vector3d const& pos) const {
    return Ray(pos, n_);
}

