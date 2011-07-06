import "coord.h"
class Ray {
	public:
		Ray(Coord start, Vector3d dir);
		Ray(Vector3d start, Vector3d dir);
		virtual ~Ray();
		Coord& start(){return start_;}
		Vector3d& dir(){return dir_;}


	private:
		Coord start_;
		Vector3d dir_;
};
