#import <Eigen/Core>
class Coord {
    public:
        Coord (double x, double y, double z);
        Coord (double x, double y, double z,  Vector3d u, Vector3d v, Vector3d w);
        double x(){return x;}
        double y(){return y;}
        double z(){return z;}
        Vector3d u(){return u;}
        Vector3d v(){return v;}
        Vector3d w(){return w;}
        Vector3d pos3d(){return Vector3d(x,y,z);}
    
    private:
	double x,y,z;
	Vector3d u,v,w;

};
