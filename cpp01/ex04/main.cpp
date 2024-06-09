#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

#define EXPECTED_ARG_COUNT 4

static void searchAndReplace(std::string &str, const std::string &toReplace, const std::string &replacing)
{
	const size_t toReplaceLen = toReplace.length();
	const size_t replacingLen = replacing.length();
	size_t currentCursor = str.find(toReplace);

	while (currentCursor != std::string::npos) //npos : end of string
	{
		str.erase(currentCursor, toReplaceLen);
		str.insert(currentCursor, replacing);
		currentCursor = str.find(toReplace, currentCursor + replacingLen);
	}
}

static bool openFile(const std::string &filename, std::ifstream &stream)
{
    stream.open("./" + filename, std::ios::binary);
    if (!stream)
    {
        std::cout << "Error: Failed to open the file named '" << filename << "'" << '\n';
        return false;
    }
	if (stream.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "Error: File named '" << filename << "' is empty." << '\n';
		stream.close();
		return false;
	}
    return true;
}

static bool createFile(const std::string &filename, std::ofstream &stream)
{
    stream.open("./" + filename + ".replace", std::ios::binary);
    if (!stream)
    {
        std::cout << "Error: Failed to create the file named '" << filename << ".replace'" << '\n';
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
	if (argc == EXPECTED_ARG_COUNT)
	{
		const std::string filename = argv[1]; //filename
		const std::string toReplace = argv[2];
		const std::string replacing = argv[3];
	
		std::ifstream oldFileStream;
		if (!openFile(filename, oldFileStream)) return 1;

		// iterator from the begining of the stream file to the end and store it in string
		std::string str((std::istreambuf_iterator<char>(oldFileStream)), std::istreambuf_iterator<char>());
		oldFileStream.close();

		std::ofstream newFileStream;
		if (!createFile(filename, newFileStream)) return 1;

		if (toReplace == replacing)
		{
			newFileStream << str;
			newFileStream.close();
			std::cout << "Note: the two strings are the same so no replacement has been made" << '\n';
			return 0;
		}
		searchAndReplace(str, toReplace, replacing);
		newFileStream << str;
		newFileStream.close();
		return 0;
	}
	std::cout << "Error: the program is should be used like so: ./ex04 filename string1 string2" << '\n';
	return 1;
}
