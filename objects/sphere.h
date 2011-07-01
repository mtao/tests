class Sphere{

	public:
		Sphere(Coord pos);
		Sphere(Coord pos, double radius);
		double intersect(ray r);
		double radius(){return radius;}
		double pos(){return pos;}

	private:
		double radius;

		Coord pos;

};
