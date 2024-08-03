#pragma once

#include "AForm.hpp"

#include <string>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm() throw(GradeTooHighException, GradeTooLowException);
		ShrubberyCreationForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException);
		ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery_creation_form);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &shrubbery_creation_form);

        void    executeForm(void) const;
    private:
        std::string _target;
};
