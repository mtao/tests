RGBColor::RGBColor(double r, double g, double b){
	rgb_[0]=r;
	rgb_[1]=g;
	rgb_[2]=b;
}
RGBColor::RGBColor(unsigned int r, unsigned int g, unsigned int b){
	rgb_[0]=r/255.0;
	rgb_[1]=g/255.0;
	rgb_[2]=b/255.0;
}

RGBColor::RGBColor(Array<double,3,1> col){
	rgb_ = col;
}

RGBColor& RGBColor::operator +(RGBColor x, RGBColor y){
	return RGBColor(x.rgb_ + y.rgb);
}
RGBColor& RGBColor::operator *(RGBColor x, RGBColor y){
	return RGBColor(x.rgb_ * y.rgb);
}
RGBColor& RGBColor::operator *(double c, RGBColor x){
	return RGBColor(c * x.rgb_);
}
RGBColor& RGBColor::operator *(RGBColor x, double c){
	return RGBColor(x.rgb_ * c);
}

void RGBColor::truncate(){
	if (rgb_[0]>1.0){rgb[0]=1.0;}
	if (rgb_[1]>1.0){rgb[1]=1.0;}
	if (rgb_[2]>1.0){rgb[2]=1.0;}
	if (rgb_[0]<0){rgb[0]=0.0}
	if (rgb_[1]<0){rgb[1]=0.0}
	if (rgb_[2]<0){rgb[2]=0.0}

}
