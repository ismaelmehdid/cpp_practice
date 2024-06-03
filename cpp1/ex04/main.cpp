#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string filename = argv[1]; //filename
		std::string first = argv[2];
		std::string second = argv[3];
		std::string res = "";
		std::ifstream oldFileStream("./" + filename, std::ios::binary); // open filename in readmode, std::ios::binary is reading bytes per bytes the content of the file so the OS don't convert some characters into anothers.
		if (!oldFileStream)
		{
			std::cout << "Error: cannot open the file you specified" << std::endl;
			return 1;
		}
		std::ofstream newFileStream("./" + filename + ".replace", std::ios::binary); // create filename
		if (!newFileStream)
		{
			std::cout << "Error: cannot create the new file" << std::endl;
			oldFileStream.close();
			return 1;
		}
		newFileStream << oldFileStream.rdbuf();
		oldFileStream.close();
		newFileStream.close();
	}
	std::cout << "Error: the program is should be use like so: ./ex04 filename string1 string2" << std::endl;
	return 1;
}