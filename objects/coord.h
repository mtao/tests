#ifndef COORD_H_
#define COORD_H_

#include <Eigen/Core>
using Eigen::Vector3d;
using Eigen::Matrix3d;

struct Coord {

    Coord (Vector3d pos_) : pos(pos_)
    {
        orient << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;
    }
    Coord (double a, double b, double c) : pos(a, b, c)
    {
        orient << 1, 0, 0,
        0, 1, 0,
        0, 0, 1;
    }
    Coord (Vector3d pos_,  Vector3d x, Vector3d y, Vector3d z) :
        pos(pos_) {orient.col(0)=x; orient.col(1)=y; orient.col(2)=z;}

    Coord (double a, double b, double c,  Vector3d x, Vector3d y, Vector3d z) :
        pos(a, b, c) {orient.col(0)=x; orient.col(1)=y; orient.col(2)=z;}

    Vector3d pos;
    Matrix3d orient;

};

#endif /* COORD_H_ */

