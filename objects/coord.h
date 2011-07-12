#ifndef COORD_H_
#define COORD_H_

#include <Eigen/Core>
using Eigen::Vector3d;

struct Coord {

    Coord (Vector3d pos) : pos(pos),
            x(1.0, 0.0, 0.0),
            y(0.0, 1.0, 0.0),
            z(0.0, 0.0, 1.0) { }
    Coord (double a, double b, double c) : pos(a, b, c),
            x(1.0, 0.0, 0.0),
            y(0.0, 1.0, 0.0),
            z(0.0, 0.0, 1.0) { }
    Coord (Vector3d pos,  Vector3d x, Vector3d y, Vector3d z) :
        pos(pos),
        x(x),
        y(y),
        z(z) {

    }
    Coord (double a, double b, double c,  Vector3d x, Vector3d y, Vector3d z) :
        pos(a, b, c),
        x(x),
        y(y),
        z(z) {

    }

    Vector3d pos, x, y, z;

};


#endif /* COORD_H_ */

