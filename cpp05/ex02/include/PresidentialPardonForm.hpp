#pragma once

#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm() throw(GradeTooHighException, GradeTooLowException);
		PresidentialPardonForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException);
		PresidentialPardonForm(const PresidentialPardonForm &presidential_pardon_form);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &presidential_pardon_form);

        void    executeForm(void) const;
    private:
        std::string _target;
};
