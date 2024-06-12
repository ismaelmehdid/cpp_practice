#include <iostream>

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return 0;
	}
	std::string str;
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		int length = str.size();
		for (int j = 0; j < length; j++)
		{
			std::cout << (char)std::toupper(str[j]);
		}
	}
	std::cout << '\n';
	return 0;
}
