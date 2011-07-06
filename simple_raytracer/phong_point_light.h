
class PhongPointLight: public LightSource {
	public:
		PhongPointLight(Coord pos, RGBColor ambient, RGBColor diffuse, RGBColor specular);
		RGBColor shade(Vector3d& incident, Vector3d& normal, Material& mat);
		
	private:
		Coord pos;
		RGBColor ambient_, diffuse_, specular_;

};
