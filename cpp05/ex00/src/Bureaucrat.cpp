#include "../include/Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat() : _name("no_name"), _grade(150)
{
	std::cout << "A bureaucrat named 'no_name' with grade 150 has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException) : _name(name), _grade(grade)
{
	if (grade > 150) {
		throw GradeTooLowException();
		return ;
	}
	else if (grade < 1) {
		throw GradeTooHighException();
		return ;
	}
	std::cout << "A bureaucrat named " << _name << " with grade " << _grade << " has been created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat) {
		*this = bureaucrat;
		std::cout << "A bureaucrat named " << _name << " with grade " << _grade << " has been created." << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "A bureaucrat named " << _name << " with grade " << _grade << " has been destroyed." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat) {
		this->_grade = bureaucrat._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::promote() throw(GradeTooHighException)
{
	if (_grade - 1 < 1) {
		throw GradeTooHighException();
		return ;
	}
	_grade--;
}

void Bureaucrat::demote() throw(GradeTooLowException)
{
	if (_grade + 1 > 150) {
		throw GradeTooLowException();
		return ;
	}
	_grade++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}