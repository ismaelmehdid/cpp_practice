#include "../include/Intern.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"

#include <iostream>

#define NBR_OF_FORMS 3

Intern::Intern()
{
    std::cout << "An intern has been hired :)" << std::endl;
}

Intern::~Intern()
{
    std::cout << "An intern has been fired :(" << std::endl;
}

AForm *createPresidentialPardonForm(const std::string &name, const std::string &target)
{
    return new PresidentialPardonForm(name, target);
}

AForm *createRobotomyRequestForm(const std::string &name, const std::string &target)
{
    return new RobotomyRequestForm(name, target);
}

AForm *createShrubberyCreationForm(const std::string &name, const std::string &target)
{
    return new ShrubberyCreationForm(name, target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    typedef AForm *(*FormCreator)(const std::string&, const std::string&);
    std::string forms[NBR_OF_FORMS] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    FormCreator funcArray[NBR_OF_FORMS] = {
        createPresidentialPardonForm,
        createRobotomyRequestForm,
        createShrubberyCreationForm
    };
    for (int i = 0; i < NBR_OF_FORMS; i++) {
        if (forms[i] == form) {
            std::cout << "Intern creates " << form << std::endl;
            return funcArray[i](form, target);
        }
    }
    std::cout << "Didn't find the form " << form << "." << std::endl;
    return NULL;
}
