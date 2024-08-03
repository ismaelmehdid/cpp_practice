#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

#include <time.h>
#include <iostream>

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXECUTE_GRADE 45

bool RobotomyRequestForm::_seeded = false;

RobotomyRequestForm::RobotomyRequestForm() throw(GradeTooHighException, GradeTooLowException)
: AForm("Robotomy Request", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXECUTE_GRADE), _target("no_name")
{
    if (!_seeded) {
        srand(time(0));
        _seeded = true;
    }
    std::cout << "A 'Robotomy Request Form' with a target named 'no_name' has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException)
: AForm(name, ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXECUTE_GRADE), _target(target)
{
    if (!_seeded) {
        srand(time(0));
        _seeded = true;
    }
    std::cout << "A 'Robotomy Request Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy_request_form)
: AForm(robotomy_request_form.getName(), robotomy_request_form.getSigningGrade(), robotomy_request_form.getExecutionGrade()), _target(robotomy_request_form._target)
{
    if (!_seeded) {
        srand(time(0));
        _seeded = true;
    }
    std::cout << "A 'Robotomy Request Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "A 'Robotomy Request Form' with a target named " << _target << " has been destroyed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy_request_form)
{
    if (this != &robotomy_request_form) {
        AForm::operator=(robotomy_request_form);
        _target = robotomy_request_form._target;
    }
    return *this;
}

void RobotomyRequestForm::executeForm(void) const
{
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized." << std::endl; 
    } else {
        std::cout << "Robotomy failed. :(" << std::endl; 
    }
}
