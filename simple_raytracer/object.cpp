/*
 * object.cpp
 *
 *  Created on: Jul 10, 2011
 *      Author: g9sash
 */

#include "object.h"
#include "coord.h"
#include "ray.h"
#include "material.h"

Object::~Object() {

}

//TODO intersect should just pass material + normal information back?
RGBColor Object::intersect(Ray const& r, unsigned int bounces_left) const {
    double lambda = intersect_lambda(r);
    Vector3d pos = r.start.pos + lambda * r.dir;
    if (bounces_left <= 0) {
        Ray inc = incident(pos);
//        return ColorOps::white;
        return mat_.intersect(r, inc);
    } else {
        //TODO: add support for moving around scene?
        //mat_intersect(r, );
        return ColorOps::black;
    }
}
