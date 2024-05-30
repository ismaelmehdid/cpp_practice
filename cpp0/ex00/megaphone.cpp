#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			int length = strlen(argv[i]);
			for (int j = 0; j < length; j++)
			{
				std::cout << (char)toupper(argv[i][j]);
			}
			if (i + 1 != argc)
			{
				std::cout << " ";
			}
		}
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
	return 0;
}
