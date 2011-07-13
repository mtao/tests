#include "simple_raytracer.h"
#include "buffer.h"

#include "Eigen/Dense"
using Eigen::Matrix3d;

#include <iostream>
using namespace std;


// Camera operates as if it is -1 in the z direction facing to +1 in z direction.
void SimpleRaytracer::render(Buffer& buffer, int fov, Coord const& cam) {
//    Matrix3d cam2world = cam.orient.inverse();

    // do solving instead of inverse, as more numerically stable...
    // although don't know what decomposition to use.
    // check http://eigen.tuxfamily.org/dox/TutorialLinearAlgebra.html
    //
    // using c++0x "auto" to let compiler deduce type (too many template parameters)
    // requires gcc 4.4+
    auto world2CamDecomposition = cam.orient.ldlt();

    /* cache width and height for for loop */
    int width = buffer.width();
    int height = buffer.height();
    double scale_factor = ::sin(fov*0.017453292519943295);
    //	double scale_factor = 1.0 / buffer.width();
    double half_width = width / 2.0;
    double half_height = height / 2.0;
    for (int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            Vector3d cam_ray_dir = Vector3d(i * scale_factor - half_width, j * scale_factor - half_height, 1);
            Ray ray(cam, world2CamDecomposition.solve(cam_ray_dir)); // using solving
//            Ray ray(cam, cam2world * cam_ray_dir); // using inverse
            buffer.setPixel(i, j, scene_.cast_ray(ray));
        }
    }

}

