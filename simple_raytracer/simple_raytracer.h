#include <Eigen/Core>
#include "../objects/ray.h"
#include "phong_material.h"
#include "scene.h"
#include "rgbcolor.h"

class SimpleRaytracer {

	public:
		SimpleRaytracer(Scene &scene) : scene_(scene) {}
		void set_scene(Scene &scene) {scene_=scene;}

		void render(int width, int height, int fov, Coord& cam);

	private:
		Scene &scene_;

};
