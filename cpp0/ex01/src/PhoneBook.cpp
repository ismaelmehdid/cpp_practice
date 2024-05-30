#include "../include/PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : m_nbrOfContacts(0)
{
	for (int i = 0; i < 8; i++)
	{
		m_contacts[i] = Contact();
 	}
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact contact)
{
	if (m_nbrOfContacts == 8)
	{
		m_contacts[7] = contact;
	}
	else
	{
		m_contacts[m_nbrOfContacts] = contact;
		m_nbrOfContacts++;
	}
}

bool	areOnlyNumbers(std::string str)
{
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (isdigit(str[i]) == false)
			return (false);
	}
	return (true);
}

void	PhoneBook::showContacts() const
{
	std::string	input;

	if (m_nbrOfContacts == 0)
	{
		std::cout << "You don't have contacts yet!" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" 
			<< std::setw(10) << "First name" << "|" 
			<< std::setw(10) << "Last name" << "|" 
			<< std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < m_nbrOfContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << m_contacts[i].get_firstName() << "|";
		std::cout << std::setw(10) << m_contacts[i].get_lastName() << "|";
		std::cout << std::setw(10) << m_contacts[i].get_nickname() << "|";
		std::cout << std::endl;
	}
	std::cin.ignore();
	do
	{
		std::cout << std::endl << "Write the index of the contact you want to display (write 'LEAVE' to exit SEARCH command) : ";
		//std::cin >> values[i];				<- wait for a non void string
		std::getline(std::cin, input); //		<- take the whole line and take an empty one if it's the case
		std::cout << std::endl;
		int index = 0; // check if only digits 
		if (!areOnlyNumbers(input) || !(stoi(input) >= 0 && stoi(input) < m_nbrOfContacts))
		{
			std::cout << "Bad input, make sure you type a number and that your index exist!" << std::endl;
		}
		else
		{
			index = stoi(input);
			std::cout << m_contacts[index].get_firstName() << std::endl;
			std::cout << m_contacts[index].get_lastName() << std::endl;
			std::cout << m_contacts[index].get_nickname() << std::endl;
			std::cout << m_contacts[index].get_phoneNumber() << std::endl;
			std::cout << m_contacts[index].get_darkestSecret() << std::endl;
		}
	} while (input != "LEAVE");
}
