#pragma once

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
		PresidentialPardonForm(const std::string &name, const int sign_grade, const int execute_grade, std::string &target) throw(GradeTooHighException, GradeTooLowException);
		PresidentialPardonForm(const PresidentialPardonForm &presidential_pardon_form);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidential_pardon_form);

        void    execute(Bureaucrat const & executor) const throw(GradeTooLowException, FormNotSignedException);
    private:
        std::string _target;
};
