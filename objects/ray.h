#ifndef RAY_H_
#define RAY_H_

#include "coord.h"
#include <Eigen/Core>

using Eigen::Vector3d;

struct Ray {
    Coord start;
    Vector3d dir;
    Ray(Coord start_, Vector3d dir_): start(start_),dir(dir_){}
    Ray(Vector3d start_,Vector3d dir_): start(Coord(start_)),dir(dir_){}
};


#endif /* RAY_H_ */

