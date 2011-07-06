double Sphere::sphere_intersect(Ray& r)
	//More numerical accuracy if the factors of 2 are removed
	//A2 denotes the value of A/2
	//<d,d>x^2 + 2<r,d>x + <p,p>=1
	//Ax^2 + Bx + C=0
	double A=r.dir.dot(r.dir);
	double B2=r.pos.dot(r.dir);
	double C=r.pos.dot(r.pos)-radius;
	//D=4b^2 - 4ac
	int D4=B2*B2-A*C;
	if (disc<0){
		return -1;
	}else{
		//need to return a positive distance
		if(B2>=0 && -B2>D4){
			return -(B2+math::sqrt(D4))/A;
		}else if(B2>D4){
			return -(B2-math::sqrt(D4))/A;
		}else{
			return 0;
		}
	}



Sphere::Sphere(coord p, Material m){
	pos=p;
	radius=1;
	mat=m;
}
Sphere::Sphere(coord p, radius r, Material m){
	pos=p;
	radius=r;
	mat=m;
}

double does_intersect(Ray& r){
	return sphere_intersect(r);

}

RGBColor Sphere::intersect(Ray& r){
	intersect(r,0);
}
//TODO intersect should just pass material + normal information back?
RGBColor Sphere::intersect(Ray& r, unsigned int bounces_left){
	double lambda=sphere_intersect(r);
	Vector3d pos=r.pos+lambda*r.dir;
	if (bounces_left<=0){
		return mat.intersect(r,pos);
	}else{
		//TODO: add support for moving around scene?
		return intersect(r,0);
	}
}

