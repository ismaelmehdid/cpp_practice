#include "../include/PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : _name("PresidentialPardonForm"), _signed(false), _sign_grade(25), _execute_grade(5)
{
	std::cout << "A form named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : _name("PresidentialPardonForm"), _signed(false), _sign_grade(25), _execute_grade(5)
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
