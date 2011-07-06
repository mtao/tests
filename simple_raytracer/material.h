#import "rgbcolor.h"
#import "scene.h"

class Material{
	public:
		virtual RGBColor intersect(Ray ray, Ray incident)=0;
	private:
		Scene* scene_;
}
