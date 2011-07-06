RGBColor SimpleScene::cast_ray(Ray ray){
	int numObjs = objects.size();
	int closest;
	double minlambda=-1;
	double newlambda;
	for(i=0; i<numObjs; i++){
		newlamnbda = objects[i].does_intersect(ray);
		if (minlambda!=-1 || (newlambda>0 && minlambda > newlambda)){
			minlambda = newlambda;
			closest=i;
		}
	}
	return objects[i].intersect(ray);
}
void SimpleScene::push_obj(Sphere obj){
	objects.push_back(obj);
}
void SimpleScene::push_light(PhongLightSource light){
	objects.push_back(light);
}
