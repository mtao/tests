#include "rgbcolor.h"
#include "scene.h"

class Material{
	public:
		virtual RGBColor intersect(Ray ray, Ray incident)=0;
	private:
		Scene* scene_;
}
