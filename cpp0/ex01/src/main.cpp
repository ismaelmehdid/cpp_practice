#include <string>
#include <iostream>
#include "../include/PhoneBook.hpp"
#include "../include/Contact.hpp"

void	addPrompt(PhoneBook &phonebook)
{
    std::string fields[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string values[5];

	std::cin.ignore();
	for (int i = 0; i < 5; i++)
	{
		while (values[i].empty())
		{
			std::cout << fields[i] << ": ";
			//std::cin >> values[i];				<- wait for a non void string
			std::getline(std::cin, values[i]); //	<- take the whole line and take an empty one if it's the case
			if (values[i].empty())
			{
				std::cout << "This field is mandatory!" << std::endl;
			}
		}
	}
	phonebook.addContact(Contact(values[0], values[1], values[2], values[3], values[4]));
}

int main(void)
{
	PhoneBook	phonebook;
	std::string	input = "";

	while (input != "EXIT")
	{
		std::cout << std::endl;
		std::cout << "Choose one of the 3 commands :" << std::endl;
		std::cout << "ADD : To add a new contact to your phonebook." << std::endl;
		std::cout << "SEARCH : To display all your contacts." << std::endl;
		std::cout << "EXIT : To exit the program." << std::endl;
	
		std::cin >> input;

		if (input == "ADD")
		{
			addPrompt(phonebook);
		}
		else if (input == "SEARCH")
		{
			phonebook.showContacts();
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

	phonebook.addContact(Contact("John", "Doe", "Johnny", "123-456-7890", "Afraid of clowns"));
    phonebook.addContact(Contact("Jane", "Smith", "Janey", "234-567-8901", "Secretly loves pineapple on pizza"));
    phonebook.addContact(Contact("Emily", "Johnson", "Em", "345-678-9012", "Has never watched Star Wars"));
    phonebook.addContact(Contact("Michael", "Williams", "Mike", "456-789-0123", "Sleeps with a nightlight"));
    phonebook.addContact(Contact("Sarah", "Brown", "Sally", "567-890-1234", "Chews ice"));
    phonebook.addContact(Contact("David", "Jones", "Dave", "678-901-2345", "Hates chocolate"));
    phonebook.addContact(Contact("Laura", "Garcia", "Laurie", "789-012-3456", "Afraid of heights"));
    phonebook.addContact(Contact("James", "Martinez", "Jim", "890-123-4567", "Addicted to reality TV"));
}