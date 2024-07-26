#include "../include/Bureaucrat.hpp"

#include <iostream>

int main(void)
{
	try {
		Bureaucrat tooLowBureaucrat = Bureaucrat("bob", 151);
	} catch (std::exception &e) {
		std::cout << "tooLowBureaucrat: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooHighBureaucrat = Bureaucrat("bob2", 0);
	} catch (std::exception &e) {
		std::cout << "tooHighBureaucrat: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooHighPromotedBureaucrat = Bureaucrat("James", 1);
		tooHighPromotedBureaucrat.promote();
	} catch (std::exception &e) {
		std::cout << "tooHighPromotedBureaucrat: " << e.what() << std::endl;
	}
	try {
		Bureaucrat tooLowDemotedBureaucrat = Bureaucrat("James", 150);
		tooLowDemotedBureaucrat.demote();
	} catch (std::exception &e) {
		std::cout << "tooLowDemotedBureaucrat: " << e.what() << std::endl;
	}
	Bureaucrat goodBureaucrat = Bureaucrat("James", 5);
	std::cout << goodBureaucrat;
	goodBureaucrat.promote();
	std::cout << goodBureaucrat;
	goodBureaucrat.demote();
	std::cout << goodBureaucrat;
}
