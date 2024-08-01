#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>  

ShrubberyCreationForm::ShrubberyCreationForm() : _name("PresidentialPardonForm"), _signed(false), _sign_grade(145), _execute_grade(137)
{
	std::cout << "A form named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _name("RobotomyRequestForm"), _signed(false), _sign_grade(145), _execute_grade(137)
{
    std::ofstream outfile(target + "_shrubbery");
    outfile << "               ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
jgs \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_";
    close(outfile);
}
