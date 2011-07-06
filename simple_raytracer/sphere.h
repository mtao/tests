class Sphere{

	public:
		Sphere(Coord pos, Material mat);
		Sphere(Coord pos, double radius);
		Sphere(Coord pos, double radius, Material mat);
		RGBColor intersect(Ray& r);
		RGBColor intersect(Ray& r, unsigned int bounces_left);
		double does_intersect(Ray r);
		double radius(){return radius;}
		double pos(){return pos;}

	private:
		double radius;
		double sphere_intersect(Ray& r);

		Coord pos;
		Material mat;

};
