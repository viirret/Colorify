#include "Cli.hh"

Cli::Cli()
{
	printf("Press \"l\" to show all premade colors\n");
	printf("Give premade color or RGB color for example \"000 255 000\"\n");

	parse();
}

void Cli::parse()
{
	std::string input;
	while(std::getline(std::cin, input))
	{
		bool flag = true;

		if(input == "l")
			list();

		else if(input == "green" || input == "Green")
		{	
			color.green();
			break;
		}
		else if(input == "red" || input == "Red")
		{
			color.red();
			break;
		}
		else if(input == "blue" || input == "Blue")
		{
			color.blue();
			break;
		}
		else
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
