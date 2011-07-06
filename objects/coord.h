#include <Eigen/Core>
class Coord {
    public:
        Coord (Vector3d pos);
        Coord (double a, double b, double c);
        Coord (Vector3d pos,  Vector3d x, Vector3d y, Vector3d z);
        Coord (double a, double b, double c,  Vector3d x, Vector3d y, Vector3d z);
        Vector3d& pos(){return pos_;}
    
    private:
	Vector3d pos_,x_,y_,z_;

};
