#include <string>
#include <stack>

void extract_element(char *input, int *i, std::string &temp)
{
    while(!std::isspace(input[i]))
    {
        temp.append(input[i]);
        (*i)++;
    }
}

double rpn(char *input)
{

    std::vector<char> = {'+', '-', '/', '*'}; 
    std::stack<int> stack;

    long res = 0;
    int i = 0;
    while (input[i])
    {
        while (std::isspace(input[i]))
            i++;
        std::string temp;
        extract_element(input, &i, temp);
        if (temp)
    }

    return res;
}
