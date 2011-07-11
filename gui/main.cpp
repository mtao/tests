#include <QtCore>
#include <QApplication>
#include <QMainWindow>

#include "RenderGui/ImageViewer.h"

#include "scene.h"
#include "phong_material.h"
#include "sphere.h"
#include "phong_point_light.h"
#include "simple_scene.h"
#include "simple_raytracer.h"
#include "RenderGui/qimage_buffer.h"


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

	PhongPointLight light(Coord(-1.0, -1.0, -1.0),
						  RGBColor(1.0,1.0,1.0),
						  RGBColor(1.0,1.0,1.0),
						  RGBColor(1.0,1.0,1.0));
	scene.push_light(&light);

	Coord cam(0,0,-1);
	SimpleRaytracer raytracer(scene);
	QImageBuffer buffer(width, height);
	raytracer.render(buffer, 60, cam);

	viewer->showImage(buffer.qimage());
	
    return a.exec();
}
