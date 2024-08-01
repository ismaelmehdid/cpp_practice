#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm(), _target("no_name")
{
    std::cout << "A 'Presidential Pardon Form' with a target named 'no_name' has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const int sign_grade, const int execute_grade, std::string &target) throw(GradeTooHighException, GradeTooLowException)
: AForm(name, sign_grade, execute_grade), _target(target)
{
    std::cout << "A 'Presidential Pardon Form' named " << 
	_name << ", with a target named " << _target << ", a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential_pardon_form) : AForm(presidential_pardon_form._name, presidential_pardon_form._sign_grade, presidential_pardon_form._execute_grade), _target(presidential_pardon_form._target)
{
    std::cout << "A 'Presidential Pardon Form' named " << 
	_name << ", with a target named " << _target << ", a signing grade of " << 
	_sign_grade << " and an executing grade of " << 
	_execute_grade << " has been created." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "A 'Presidential Pardon Form' with a target named " << _target << " has been destroyed." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidential_pardon_form)
{
    if (this != &presidential_pardon_form) {
        AForm::operator=(presidential_pardon_form);
        _target = presidential_pardon_form._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const throw(GradeTooLowException, FormNotSignedException)
{
    if (!_signed) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > _execute_grade) {
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
