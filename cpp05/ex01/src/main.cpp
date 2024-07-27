#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

#include <iostream>

int main(void)
{
    try {
        Form tooHigh = Form("tooHigh", 151, 50);
    } catch (std::exception &e) {
        std::cout << "tooHigh: " << e.what() << std::endl;
    } 
    try {
        Form tooLow = Form("tooLow", 0, 50);
    } catch (std::exception &e) {
        std::cout << "tooLow: " << e.what() << std::endl;
    } 
}
