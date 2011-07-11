#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "object.h"
#include "rgbcolor.h"
#include "coord.h"

class Material;

class Triangle : public Object {

	public:
		//Assume that the input is given in clockwise for orientation
		Triangle(Vector3d v1, Vector3d v2, Vector3d v3, Material& mat)
			:Object(mat),v1_(v1),v2_(v2),v3_(v3),normal_((v2-v1).cross(v3-v1))
			{normal_.normalize();}
		double intersect_lambda(Ray const& r) const;
		Ray incident(Vector3d const& pos) const;

	private:
		Vector3d v1_, v2_, v3_, normal_;

};


#endif /* TRIANGLE_H_ */

