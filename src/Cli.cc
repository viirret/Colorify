#include "Cli.hh"

Cli::Cli()
{
	printf("Press \"l\" to show all premade colors\n");
	printf("Give premade color or RGB colors for example \"000 255 000\"\n");
	parse();
}

void Cli::parse()
{
	std::string input;
	for(;;)
	{
		std::getline(std::cin, input);
		if(input == "l")
			list();

		else if(input == "green" || input == "Green")
		{	
			color.green();
			break;
		}
		else
		{
			std::stringstream stream(input);
			for(int i = 0; i < 3; i++)
			{
				int n;
				stream >> n;

				if(i == 0)
					r = n;

				else if(i == 1)
					g = n;

				else if(i == 2)
				{
					b = n;
					convert();
					break;
				}
			}
			break;
		}
	}
}

void Cli::list()
{
	printf("green\n");
}

void Cli::convert()
{
	color.r = (float)r / 255;
	color.g = (float)g / 255;
	color.b = (float)b / 255;
}
