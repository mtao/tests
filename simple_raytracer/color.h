class Color {
	public:
		virtual Color operator +(Color x, Color y) = 0;
		virtual Color operator *(Color x, Color y) = 0;
		virtual Color operator *(double c, Color x) = 0;
		virtual Color operator *(Color x, double c) = 0;

};
