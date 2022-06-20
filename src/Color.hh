#ifndef COLOR_HH
#define COLOR_HH

#include <string>

class Color
{
	public:
		float r, g, b;
		bool equalsInput(std::string const& input, Color& color);

	private:
		void green();
		void red();
		void blue();
		void black();
		void white();	
		void yellow();
		void pink();
		void orange();
		void purple();
		void lightblue();
		void brown();
		void grey();
		void lightgrey();
		void lime();
		void turquoise();
};

#endif
