#include "Cli.hh"

Cli::Cli()
{
	printf("Press \"l\" to show all premade colors\n");
	printf("Give premade color or RBD decimal for example \"000 255 000\"\n");

	parse();
}

void Cli::parse()
{
	std::string input;
	while(std::getline(std::cin, input))
	{
		// check for correct input
		bool flag = true;

		if(input == "l")
			list();
		
		// check if input is color name
		if(!color.equalsInput(input, color))
		{
			std::stringstream ss(input);
			for(size_t i = 0; i < 3; i++)
			{
				int n;
				ss >> n;

				if(ss.fail())
				{
					printf("RGB value needs three arguments\n");
					flag = false;
					break;
				}
				else
				{
					switch(i)
					{
						case 0: r = n; break;
						case 1: g = n; break;
						case 2: b = n; convert(); break;
					}
				}
			}
			if(!flag)
			{
				printf("Wrong input!\n");
				continue;
			}
			break;
		}
		break;
	}
}

void Cli::list()
{
	printf("green\nred\nblue\nwhite\nblack\nwhite\nyellow\npink\norange\npurple\nlightblue\nbrown\n" );
}

void Cli::convert()
{
	color.r = (float)r / 255;
	color.g = (float)g / 255;
	color.b = (float)b / 255;
}
