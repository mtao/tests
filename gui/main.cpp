#include <QtCore>
#include <QApplication>
#include <QMainWindow>

#include "src/ImageViewer.h"

#include "scene.h"
#include "phong_material.h"
#include "sphere.h"
#include "phong_point_light.h"
#include "simple_scene.h"
#include "simple_raytracer.h"
#include "plane.h"
#include "src/qimage_buffer.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow* window = new QMainWindow();
    RenderGui::Viewer* viewer = new RenderGui::Viewer();
    window->setCentralWidget(viewer);
    window->show();

    int width = 320;
    int height = 240;

    SimpleScene scene;
    PhongMaterial metal(scene,
            RGBColor(0.1,0.1,0.1),
            RGBColor(0.8,0.8,0.8),
            RGBColor(0.8,0.8,0.8),
            2.0);

    Sphere sphere(Coord(0,0,4), metal);
    scene.push_obj(&sphere);
//    Plane plane(Vector3d(1.0,0.0,0.0),
//                Vector3d(0.0,1.0,0.0),
//                Vector3d(0.0,0.0,-1.0),
//                metal);
//    scene.push_obj(&plane);

    PhongPointLight light(Coord(-1.0, -1.0, -1.0),
            RGBColor(1.0,1.0,1.0),
            RGBColor(1.0,1.0,1.0),
            RGBColor(1.0,1.0,1.0));
    scene.push_light(&light);

    Coord cam(0,0,-1);
    SimpleRaytracer raytracer(scene);
    QImageBuffer buffer(width, height);
    raytracer.render(buffer, 60, cam);

    //buffer.setPixel(50, 50, ColorOps::white);
    viewer->showImage(buffer.qimage());

    return a.exec();
}
