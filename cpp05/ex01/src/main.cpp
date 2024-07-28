#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

#include <iostream>

int main(void)
{
    std::cout << "\033[31mForm creation test: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
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
    std::cout << std::endl;
    std::cout << "\033[31mOperator overload test: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    Form goodForm = Form("myForm", 90, 20);
    std::cout << goodForm;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << std::endl;

    std::cout << "\033[31mBureaucrat too low to sign test: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    Bureaucrat goodBureaucrat = Bureaucrat("myBureaucrat", 91);
    try {
        goodForm.beSigned(goodBureaucrat);
    } catch (std::exception &e) {
        std::cout << "Too low to sign test: " << e.what() << std::endl;
    }
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << std::endl;

    // Bureaucrat can sign the form because his grade is high enough
    std::cout << "\033[31mBureaucrat can sign test: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    goodBureaucrat.promote();
    try {
        goodForm.beSigned(goodBureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << goodForm;

    goodBureaucrat.signForm(goodForm);
    goodBureaucrat.demote();
    goodBureaucrat.signForm(goodForm);
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
}
