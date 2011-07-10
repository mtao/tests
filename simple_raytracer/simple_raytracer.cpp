#include "simple_raytracer.h"

Matrix3d SimpleRaytracer::world2cam(Coord& coord){
	Matrix3d ret;
	for(int i=0;i<3; i++){
		ret[i][0]=coord.x()[i];
		ret[i][1]=coord.y()[i];
		ret[i][2]=coord.z()[i];
	}
	return ret;
}


// Camera operates as if it is -1 in the z direction facing to +1 in z direction.
void SimpleRaytracer::render(int width, int height, int fov, Coord& cam) {
	Color** screen=malloc(sizeof(RGBColor*) * width);

	if (screen==NULL){return -1;}

	for(int i=0; i<WIDTH; i++){
		screen[i]=malloc(sizeof(RGBColor) * height);
		if (screen[i]==NULL){return -1;}
	}

	Matrix3d world2cam = world2cam(cam);
	Matrix3d cam2world = world2cam.inverse();
	double scale_factor = 1.0/HEIGHT;
	for (int i=0; i < width; i++){
		for(j=0; j < height; j++){
			Vector3d cam_ray_dir = Vector3d(i*scale_factor,j*scale_factor,1);
			Ray ray(cam, cam2world * cam_ray_dir);
			screen[i][j] = scene.cast_ray(ray);
		}
	}

}
