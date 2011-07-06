PhongPointLight(Coord pos, RGBColor ambient, RGBColor diffuse, RGBColor specular){
	pos_=pos;
	ambient_=ambient;
	diffuse_=diffuse;
	specular_=specular;
}

RGBColor PhongPointLight::shade(Ray& ray, Ray& incident, Material* mat){
	Vector3d ray_dir=ray.dir().normalized();//faces into the object
	Vector3d normal=incident.dir().normalized();
	Vector3d light_dir=(pos_-incident.pos()).normalized();//from point to light source

	double incident_angle=ray_dir.dot(normal);
	double reflected_angle_diff=ray_dir.dot(2*(normal.dot(light_dir)*normal-light_dir));
	return mat.ambient()*ambient
	       + angle*(diffuse_*mat->diffuse()) 
	       + math::pow(reflected_angle_diff,mat->specular_pow())*mat->specular() * specular_;
}
