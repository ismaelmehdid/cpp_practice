#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

#include <string>
#include <iostream>

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
		std::cout << '\n';
		std::cout << "Choose one of the 3 commands :" << '\n';
		std::cout << "ADD : To add a new contact to your phonebook." << '\n';
		std::cout << "SEARCH : To display all your contacts." << '\n';
		std::cout << "EXIT : To exit the program." << '\n';
		std::cout << "Command: ";
		if (std::getline(std::cin, input).eof()) //Take the whole line (exept the \n) and go to nextline (so no need to cin.ignore)
		{
			return 0;
		}
		if (input == "ADD")
		{
			if (addPrompt(phonebook) != 0)
				return 0;
		}
		else if (input == "SEARCH")
		{
			phonebook.displayContacts();
			if (phonebook.promptForContact() != 0)
				return 0;
		}
		else if (input == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Wrong input, please try again." << '\n';
		}
	}
}