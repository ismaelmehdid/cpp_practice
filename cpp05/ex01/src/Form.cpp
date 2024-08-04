#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

#include <iostream>

Form::Form() : _name("no_name"), _signed(false), _sign_grade(1), _execute_grade(1)
{
	std::cout << "A form named 'no_name' with a signing grade of 1 and an executing grade of 1 has been created." << std::endl;
}

Form::Form(const std::string &name, const int sign_grade, const int execute_grade) throw(GradeTooHighException, GradeTooLowException) :
_name(name), _signed(false), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	if (sign_grade < 1 || execute_grade < 1) {
		throw GradeTooHighException();
	}
	else if (sign_grade > 150 || execute_grade > 150) {
		throw GradeTooLowException();
	}
    std::cout << "A form named " << _name << " with a signing grade of " << _sign_grade << " and an executing grade of " << _execute_grade << " has been created." << std::endl;
}

Form::Form(const Form &form) : _name(form._name), _signed(form._signed), _sign_grade(form._sign_grade), _execute_grade(form._execute_grade)
{
	std::cout << "A form named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

Form::~Form()
{
	std::cout << "A form named " << 
	_name << " with a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been destroyed." << std::endl;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form) {
		_signed = form._signed;
	}
	return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getSigningGrade() const
{
    return _sign_grade;
}

int Form::getExecutionGrade() const
{
    return _execute_grade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException)
{
    if (bureaucrat.getGrade() > _sign_grade) {
        throw GradeTooLowException();
    }
    _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName() <<
    (form.isSigned() ? " (signed)" : " (not signed)") <<
    ", signing grade " << form.getSigningGrade() <<
    ", execution grade " << form.getExecutionGrade() <<
    "." << std::endl;
	return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade too low!";
}