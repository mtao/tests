#include "sphere.h"
#include "ray.h"
#include "math.h"
#include "material.h"
#include <iostream>
using namespace std;

double Sphere::intersect_lambda(Ray const& r) const {
	//More numerical accuracy if the factors of 2 are removed
	//A2 denotes the value of A/2
	//<d,d>x^2 + 2<r,d>x + <p,p>=1
	//Ax^2 + Bx + C=0
	double A = r.dir.dot(r.dir);
	double B2 = r.start.pos.dot(r.dir);
	double C = r.start.pos.dot(r.start.pos) - radius_;
	//D=4b^2 - 4ac
	int D4 = B2 * B2 - A * C;
	if (D4 < 0) {
		return -1;
	} else {
		//need to return a positive distance
		if (B2 >= 0 && -B2 > D4) {
			return -(B2 + ::sqrt(D4)) / A;
		}
		else if (B2 > D4) {
			return -(B2 - ::sqrt(D4)) / A;
		}
		else {
			return 0;
		}
	}
}

Ray Sphere::incident(Vector3d const& pos) const {
	cout << "intersected with sphere\n";
	return Ray(pos,pos.normalized());
}
