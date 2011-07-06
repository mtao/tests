class Scene{
	public:
		virtual RGBColor * cast_ray(Ray r)=0;
		virtual void push_obj(Object o)=0;
		virtual void push_light(Object o)=0;
	private:
		//TODO:these need to be actually defined and push stuff need to be implemented
		//simple_scene covers these by only assuming sphere/phong point lights
		ObjectStructure objects_;
		LightStructure lights_;
}
