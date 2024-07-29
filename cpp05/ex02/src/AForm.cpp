#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

#include <iostream>

AForm::AForm(const AForm &AForm) : _name(AForm._name), _signed(AForm._signed), _sign_grade(AForm._sign_grade), _execute_grade(AForm._execute_grade)
{
	std::cout << "A AForm named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

AForm &AForm::operator=(const AForm &AForm)
{
	if (this != &AForm) {
		_signed = AForm._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getSigningGrade() const
{
    return _sign_grade;
}

int AForm::getExecutionGrade() const
{
    return _execute_grade;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException)
{
    if (bureaucrat.getGrade() > _sign_grade) {
        throw GradeTooLowException();
    }
    _signed = true;
}
