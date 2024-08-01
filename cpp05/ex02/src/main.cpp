#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

#include <iostream>

int main(void)
{
    Bureaucrat myBur = Bureaucrat("Boby", 1);
    std::string name = "salut";
    std::string target = "bob";
    PresidentialPardonForm test = PresidentialPardonForm(name, 13, 42, target);
    myBur.signForm(test);
    try {
        test.execute(myBur);
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
