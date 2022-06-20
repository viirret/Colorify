#ifndef CLI_HH
#define CLI_HH

#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include "Color.hh"

class Cli
{
	public:
		Cli();
		Color color;
		void convert();
		void list();
		void parse();

	private:
		int r, g, b;
};

#endif
