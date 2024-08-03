#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

#define SHRUBBERY_SIGN_GRADE 72
#define SHRUBBERY_EXECUTE_GRADE 45

ShrubberyCreationForm::ShrubberyCreationForm() throw(GradeTooHighException, GradeTooLowException)
: AForm("Shruberry Creation", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXECUTE_GRADE), _target("no_name")
{
    std::cout << "A 'Shruberry Creation Form' with a target named 'no_name' has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, const std::string &target) throw(GradeTooHighException, GradeTooLowException)
: AForm(name, SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXECUTE_GRADE), _target(target)
{
    std::cout << "A 'Shruberry Creation Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubbery_creation_form)
: AForm(shrubbery_creation_form.getName(), shrubbery_creation_form.getSigningGrade(), shrubbery_creation_form.getExecutionGrade()), _target(shrubbery_creation_form._target)
{
    std::cout << "A 'Shruberry Creation Form' named " << 
	getName() << ", with a target named " << _target << ", a signing grade of " << 
	getSigningGrade() << " and an executing grade of " << 
	getExecutionGrade() << " has been created." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "A 'Shruberry Creation Form' with a target named " << _target << " has been destroyed." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubbery_creation_form)
{
    if (this != &shrubbery_creation_form) {
        AForm::operator=(shrubbery_creation_form);
        _target = shrubbery_creation_form._target;
    }
    return *this;
}

void ShrubberyCreationForm::executeForm(void) const
{
    std::ofstream outfile(_target + "_shrubbery");
    outfile << "               ,@@@@@@@,\n"
       "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\\\88/8o\n"
   "   ,%&\\\\%&&%&&%,@@@\\\\@@@/@@@88\\\\88888/88'\n"
   "   %&&%&%&/%&&%@@\\\\@@/ /@@@88888\\\\88888'\n"
   "   %&&%/ %&%%&&@@\\\\ V /@@' `88\\\\8 `/88'\n"
   "   `&%\\\\ ` /%&'    |.|        \\\\ '|8'\n"
       "       |o|        | |         | |\n"
       "       |.|        | |         | |\n"
"jgs \\\\/ ._\\\\//_/__/  ,_\\\\//__\\\\/.  \\\\_//__/_";
}
