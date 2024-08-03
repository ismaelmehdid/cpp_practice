#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

#include <iostream>

int main(void)
{
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << "\033[31mForm not signed and try to execute: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    {
        Bureaucrat myBur = Bureaucrat("Boby", 1);
        PresidentialPardonForm test = PresidentialPardonForm("Presidential Pardon", "bob");
        try {
            myBur.executeForm(test);
        } catch (std::exception &e){
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << "\033[31mBureaucrat grade too low to execute the form: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    {
        Bureaucrat myBur = Bureaucrat("Boby", 1);
        PresidentialPardonForm test = PresidentialPardonForm("Presidential Pardon", "bob");
        myBur.signForm(test);
        Bureaucrat myLowBur = Bureaucrat("BobyLow", 6);
        try {
            myLowBur.executeForm(test);
        } catch (std::exception &e){
           std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << "\033[31mExecution of Robotomy Request Form: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    {
        try {
            Bureaucrat myBur = Bureaucrat("Bob", 1);
            RobotomyRequestForm myForm = RobotomyRequestForm("Destroyer", "Boby");
            myBur.signForm(myForm);
            for (int i = 0; i < 10; i++) {
                std::cout << "---------------" << std::endl;
                myBur.executeForm(myForm);
            }
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << "\033[31mExecution of Shrubbery Creation Form: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    {
        try {
            Bureaucrat myBur = Bureaucrat("Bob", 1);
            ShrubberyCreationForm myForm = ShrubberyCreationForm("Tree", "Home");
            myBur.signForm(myForm);
            myBur.executeForm(myForm);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    std::cout << "\033[31mPresidential Pardon Form: \033[0m" << std::endl;
    std::cout << "\033[31m-------------------------\033[0m" << std::endl;
    {
        try {
            Bureaucrat myBur = Bureaucrat("Bob", 1);
            PresidentialPardonForm myForm = PresidentialPardonForm("Pardon", "Home");
            myBur.signForm(myForm);
            myBur.executeForm(myForm);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
