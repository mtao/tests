#import <Eigen/Core>
class coord {
    public:
        cord (double x, double y, double z);
        cord (double x, double y, double z,  Matrix<double, 3,1> e1,Matrix<double, 3,1> e2,Matrix<double, 3,1> e3);
        double x(){return coord[3,0];}
        double y(){return coord[3,1];}
        double z(){return coord[3,2];}
        Vector3d pos3d(){return Vector3d(x,y,z);}
        Vector4d pos4d(){return Vector4d(x,y,z,1);}
    
    private:
        Matrix<double,4,4> coord;
};
