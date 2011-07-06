class Color{
	public:
		virtual Color operator +(Color y) = 0;
		virtual Color operator *(Color y) = 0;
		virtual Color operator *(double c) = 0;
};
