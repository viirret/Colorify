#ifndef CLI_HH
#define CLI_HH

#include <cstdio>
#include "Color.hh"

class Cli
{
	public:
		Cli();
		Color color;
		void convert();
	private:
		int r, g, b;
};

#endif
