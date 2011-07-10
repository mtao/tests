/*
 * object.h
 *
 *  Created on: Jul 10, 2011
 *      Author: g9sash
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "coord.h"
#include "rgbcolor.h"
class Ray;

class Object {

public:
	virtual ~Object();

public:
	virtual RGBColor intersect(Ray const& r, unsigned int bounces_left = 0) const = 0;
	virtual Coord pos() const = 0;
	virtual double does_intersect(Ray const& r) const = 0;

};

#endif /* OBJECT_H_ */
