#ifndef RAY_H_
#define RAY_H_

#include "coord.h"
#include <Eigen/Core>

using Eigen::Vector3d;

struct Ray {
	Coord start;
	Vector3d dir;
};


#endif /* RAY_H_ */

