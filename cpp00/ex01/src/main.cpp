#include <string>
#include <iostream>
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	input = "";

	/* Tests */
	phonebook.addContact(Contact("Johnnnnnnn", "Doe", "Johnny", "123-456-7890", "Afraid of clowns"));
    phonebook.addContact(Contact("Jane", "Smithhhhhhhhhhhh", "Janey", "234-567-8901", "Secretly loves pineapple on pizza"));
    phonebook.addContact(Contact("Emily", "Johnson", "Em", "345-678-9012", "Has never watched Star Wars"));
    phonebook.addContact(Contact("Michael", "Williams", "Mike", "456-789-0123", "Sleeps with a nightlight"));
	/*-------*/

	while (input != "EXIT")
	{
		std::cout << std::endl;
		std::cout << "Choose one of the 3 commands :" << std::endl;
		std::cout << "ADD : To add a new contact to your phonebook." << std::endl;
		std::cout << "SEARCH : To display all your contacts." << std::endl;
		std::cout << "EXIT : To exit the program." << std::endl;
		std::cout << "Command: ";
		std::getline(std::cin, input); //Take the whole line (exept the \n) and go to nextline (so no need to cin.ignore)
		if (input == "ADD")
		{
			addPrompt(phonebook);
		}
		else if (input == "SEARCH")
		{
			phonebook.displayContacts();
			phonebook.promptForContact();
		}
		else if (input == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Wrong input, please try again." << std::endl;
		}
	}
}