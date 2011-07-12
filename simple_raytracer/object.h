/*
 * object.h
 *
 *  Created on: Jul 10, 2011
 *      Author: g9sash
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "rgbcolor.h"
using Eigen::Vector3d;
class Ray;
class Material;

class Object {

public:
    Object(Material& mat): mat_(mat) { }
    virtual ~Object();
    virtual double intersect_lambda(Ray const& r) const = 0;
    virtual Ray incident(Vector3d const& pos) const = 0;
    RGBColor intersect(Ray const& r, unsigned int bounces_left = 0) const;
private:
    Material& mat_;

};

#endif /* OBJECT_H_ */
