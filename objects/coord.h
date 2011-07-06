#import <Eigen/Core>
class Coord {
    public:
        Coord (double x, double y, double z);
        Coord (double x, double y, double z,  Vector3d i, Vector3d j, Vector3d k);
        double x(){return x_;}
        double y(){return y_;}
        double z(){return z_;}
        Vector3d u(){return i_;}
        Vector3d v(){return j_;}
        Vector3d w(){return k_;}
        Vector3d pos3d(){return Vector3d(x,y,z);}
    
    private:
	double x_,y_,z_;
	Vector3d i_,j_,k_;

};
