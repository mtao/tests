import "coord.h"
class Ray {
	public:
		Ray(coord start, Vector3d dir);
		Ray(Vector3d start, Vector3d dir);
		virtual ~Ray();


	private:
		Coord start;
		Vector3d dir;
};
