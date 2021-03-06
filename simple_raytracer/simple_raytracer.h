#ifndef SIMPLE_RAYTRACER_H_
#define SIMPLE_RAYTRACER_H_

#include <Eigen/Core>
#include "../objects/ray.h"
#include "phong_material.h"
#include "scene.h"
#include "rgbcolor.h"

class Buffer;

class SimpleRaytracer {

public:
    SimpleRaytracer(Scene &scene) : scene_(scene) { }
    void set_scene(Scene &scene) { scene_ = scene; }

    void render(Buffer& buffer, int fov, Coord const& cam);

private:
    Scene &scene_;

};


#endif /* SIMPLE_RAYTRACER_H_ */

