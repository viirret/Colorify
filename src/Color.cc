#include "Color.hh"

void Color::green() { r = 0.0f; g = 1.0f; b = 0.0f; }
void Color::red() { r = 1.0f; g = 0.0f; b = 0.0f; }
void Color::blue() { r = 0.0f; g = 0.0f; b = 1.0f; }
void Color::black() { r = 0.1f; g = 0.1f; b = 0.1f; }
void Color::white() { r = 1.0f; g = 1.0f; b = 1.0f; }
void Color::yellow() { r = 0.87f; g = 0.87f; b = 0.0f; }
void Color::pink() { r = 0.87f; g = 0.0f; b = 0.435f;}
void Color::orange() { r = 1.0f; g = 0.55f; b = 0.0f; }
void Color::purple() { r = 0.87f; g = 0.63f; b = 0.87f; }
void Color::lightblue() { r = 0.69f; g = 0.87f; b = 0.9f; }
void Color::brown() { r = 0.59f; g = 0.29f; b = 0.0f; }
void Color::grey() { r = 0.25f; g = 0.25f; b = 0.25f; }
void Color::lightgrey() { r = 0.5f; g = 0.5f; b = 0.5f; }
void Color::lime() { r = 0.47f; g = 0.745f; b = 0.13f; }
void Color::turquoise() { r = 0.25f; g = 0.87f; b = 0.815f; }

bool Color::equalsInput(std::string const& input, Color& color)
{
	if(input == "green" || input == "Green")
	{
		color.green();
		return true;
	}
	else if(input == "red" || input == "Red")
	{
		color.red(); 
		return true;
	}
	else if(input == "blue" || input == "Blue")
	{
		color.blue();
		return true;
	}
	else if(input == "black" || input == "Black")
	{
		color.black();
		return true;
	}
	else if(input == "white" || input == "White")
	{
		color.white();
		return true;
	}
	else if(input == "yellow" || input == "Yellow")
	{
		color.yellow();
		return true;
	}
	else if(input == "pink" || input == "Pink")
	{
		color.pink();
		return true;
	}
	else if(input == "orange" || input == "Orange")
	{
		color.orange();
		return true;
	}
	else if(input == "purple" || input == "Purple")
	{
		color.purple();
		return true;
	}
	else if(input == "lightblue" || input == "Lightblue")
	{
		color.lightblue();
		return true;
	}
	else if(input == "brown" || input == "Brown")
	{
		color.brown();
		return true;
	}
	else if(input == "grey" || input == "Grey")
	{
		color.grey();
		return true;
	}
	else if(input == "lightgrey" || input == "Lightgrey")
	{
		color.lightgrey();
		return true;
	}
	else if(input == "lime" || input == "Lime")
	{
		color.lime();
		return true;
	}
	else if(input == "turquoise" || input == "Turquoise")
	{
		color.turquoise();
		return true;
	}

	else
		return false;
}

