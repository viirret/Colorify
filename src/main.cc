#include "Program.hh"

int main()
{
	Program p;

	while(!p.close)
		p.run();
	
	return 0;
}
