#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

#include <iostream>

#define PRESIDENTIAL_SIGN_GRADE 25
#define PRESIDENTIAL_EXECUTE_GRADE 5

PresidentialPardonForm::PresidentialPardonForm() throw(GradeTooHighException, GradeTooLowException)
: AForm("Presidential Pardon", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXECUTE_GRADE), _target("no_name")
{
    std::cout << "A 'Presidential Pardon Form' with a target named 'no_name' has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException)
: AForm(name, PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXECUTE_GRADE), _target(target)
{
    std::cout << "A 'Presidential Pardon Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidential_pardon_form)
: AForm(presidential_pardon_form.getName(), presidential_pardon_form.getSigningGrade(), presidential_pardon_form.getExecutionGrade()), _target(presidential_pardon_form._target)
{
    std::cout << "A 'Presidential Pardon Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
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

void PresidentialPardonForm::executeForm(void) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
