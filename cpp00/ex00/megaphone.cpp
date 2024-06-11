#include <iostream>

int mystrlen(char *str)
{
	if (str == NULL)
	{
		return 0;
	}
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			int length = mystrlen(argv[i]);
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
	std::cout << '\n';
	return 0;
}
