class PhongMaterial: public Material {
	public:
		PhongMaterial(Scene* scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow);
		PhongMaterial(Scene* scene, RGBColor ambient, RGBColor diffuse, RGBColor specular, double specular_pow, bool translucent);
	private:
		RGBColor ambient_;
		RGBColor diffuse_;
		RGBColor specular_;
		double specular_pow_;
		bool translucent_;
};
