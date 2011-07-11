#ifndef PLANE_H_
#define PLANE_H_

#include "object.h"
#include "rgbcolor.h"
#include "coord.h"

class Material;

class Plane: public Object {

	public:
		~Plane(){}

		Plane(Vector3d x, Vector3d y, Vector3d n, Material& mat)
			:Object(mat), x_(x), y_(y), n_(n)
				{n_.normalize();}
		double intersect_lambda(Ray const& r) const;
		Ray incident(Vector3d const& pos) const;

	private:
		Vector3d x_,y_,n_;

};


#endif /* PLANE_H_ */

