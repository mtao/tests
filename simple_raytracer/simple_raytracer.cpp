#include "simple_raytracer.h"
#include "buffer.h"

#include "Eigen/Core"
#include "Eigen/LU"
using Eigen::Matrix3d;

#include <iostream>
using namespace std;


// Camera operates as if it is -1 in the z direction facing to +1 in z direction.
void SimpleRaytracer::render(Buffer& buffer, int fov, Coord const& cam) {


    Matrix3d cam2world = cam.orient.inverse();
    double scale_factor = ::sin(fov*0.017453292519943295);
    //	double scale_factor = 1.0 / buffer.width();
    double half_width=buffer.width()/2.0;
    double half_height=buffer.width()/2.0;
    for (int i = 0; i < buffer.width(); i++) {
        for(int j = 0; j < buffer.height(); j++) {
            Vector3d cam_ray_dir = Vector3d(i * scale_factor-half_width, j * scale_factor-half_height, 1);
            Ray ray(cam, cam2world * cam_ray_dir);
            buffer.setPixel(i,j, scene_.cast_ray(ray));
        }
    }

}

