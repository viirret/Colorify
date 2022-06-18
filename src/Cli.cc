#include "Cli.hh"

Cli::Cli()
{
	printf("Give rgb values\n");
	scanf("%d %d %d", &r, &g, &b);
	convert();
}

void Cli::convert()
{
	color.r = (float)r / 255;
	color.g = (float)g / 255;
	color.b = (float)b / 255;
}
