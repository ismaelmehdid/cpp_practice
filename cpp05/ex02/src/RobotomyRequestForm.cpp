#include "../include/RobotomyRequestForm.hpp"

#include <iostream>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : Form::_name("PresidentialPardonForm"), _signed(false), _sign_grade(72), _execute_grade(45)
{
	std::cout << "A form named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : _name("RobotomyRequestForm"), _signed(false), _sign_grade(72), _execute_grade(45)
{
    if (rand() % 2 == 0) {
        std::cout << target << " has been robotomized." << std::endl; 
    }
    std::cout << "Robotomy failed. :(" << std::endl; 
}
