#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"

#include <iostream>

int main(void)
{
    Intern someRandomIntern;

    AForm *form_ptr;
    form_ptr = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form_ptr) {
        delete form_ptr;
    }

    std::cout << "-----------------------" << std::endl;

    form_ptr = someRandomIntern.makeForm("presidential pardon", "Bender");
    if (form_ptr) {
        delete form_ptr;
    }

    std::cout << "-----------------------" << std::endl;

    form_ptr = someRandomIntern.makeForm("shrubbery creation", "Bender");
    if (form_ptr) {
        delete form_ptr;
    }

    std::cout << "-----------------------" << std::endl;

    form_ptr = someRandomIntern.makeForm("blop", "Bender");
    if (form_ptr) {
        delete form_ptr;
    }
}
