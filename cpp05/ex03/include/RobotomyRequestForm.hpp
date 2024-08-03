#pragma once

#include "AForm.hpp"

#include <string>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm() throw(GradeTooHighException, GradeTooLowException);
		RobotomyRequestForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException);
		RobotomyRequestForm(const RobotomyRequestForm &robotomy_request_form);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomy_request_form);

        void    executeForm(void) const;
    private:
        std::string _target;
        static bool _seeded;
};
