#include "sphere.h"
#include "ray.h"
#include "math.h"
#include "material.h"
#include <iostream>
using namespace std;

double Sphere::intersect_lambda(Ray const& r) const {
    // TODO opportunity to somehow cache some of the dot products,
    // since origins of all the ray are the same point?

    //change the ray into local coordinates
    Ray ray(r.start.pos - coord_.pos, coord_.orient * r.dir);

    double A = ray.dir.dot(ray.dir);
    double B = 2*ray.start.pos.dot(ray.dir);
    double C = ray.start.pos.dot(ray.start.pos) - radius_;
    double D = B*B - 4 * A * C;
    if (D<0) {return -1.0;}
    double s1=(-B-::sqrt(D))/(2*A);
    double s2=(-B+::sqrt(D))/(2*A);
    return ::min(::max(s1,0.0),max(s2,0.0));

    //More numerical accuracy if the factors of 2 are removed
    //A2 denotes the value of A/2
    //<d,d>x^2 + 2<r,d>x + <p,p>=1
    //Ax^2 + Bx + C=0`
//    double A = ray.dir.dot(ray.dir);
//    double B2 = ray.start.pos.dot(ray.dir);
//    double C = ray.start.pos.dot(ray.start.pos) - radius_;
//    //D=4b^2 - 4ac
//    int D4 = B2 * B2 - A * C;
//    if (D4 < 0) {
//        return -1;
//    } else {
//        //need to return a positive distance
//        if (B2 < -D4) {
//            double BmD=-(B2+::sqrt(D4));
//            if (abs(C/A)<1)//C<A
//            return -(B2 + ::sqrt(D4)) / A;
//        }
//        else if (B2 <= 0 && B2 > D4) {
//            return -C/(B2 - ::sqrt(D4));
//        }
//        else {
//            return 0;
//        }
//    }
}

Ray Sphere::incident(Vector3d const& pos) const {
    return Ray(coord_,(pos - coord_.pos).normalized());
}
