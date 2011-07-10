#include "simple_raytracer.h"
#include "Eigen/Core"
#include "Eigen/LU"
using Eigen::Matrix3d;
typedef Eigen::Array<RGBColor, Eigen::Dynamic, Eigen::Dynamic> Image;

namespace {

	Matrix3d world2cam(Coord& coord) {
		Matrix3d ret;
		ret.col(0) = coord.x;
		ret.col(1) = coord.y;
		ret.col(2) = coord.z;
		return ret;
	}

}

// Camera operates as if it is -1 in the z direction facing to +1 in z direction.
void SimpleRaytracer::render(int width, int height, int fov, Coord& cam) {
	Image screen(width, height);

	Matrix3d w2c = world2cam(cam);
	Matrix3d cam2world = w2c.inverse();
	double scale_factor = 1.0 / height;
	for (int i = 0; i < width; i++) {
		for(int j = 0; j < height; j++) {
			Vector3d cam_ray_dir = Vector3d(i * scale_factor, j * scale_factor, 1);
			Ray ray = {cam, cam2world * cam_ray_dir};
			screen(i,j) = scene_.cast_ray(ray);
		}
	}

}

