#include <vector>
class SimpleScene: Scene{
	public:
		SimpleScene();
	private:
		vector<	Sphere > objects();
		vector< PhongPointLight > lights();
}
