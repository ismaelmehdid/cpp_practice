#include "../include/PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : m_nbrOfContacts(0), m_currentIndex(0)
{
	for (int i = 0; i < 8; i++)
	{
		m_contacts[i] = Contact();
 	}
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(Contact contact)
{
	m_contacts[m_currentIndex] = contact;
	m_currentIndex = (m_currentIndex + 1) % 8;
	if (m_nbrOfContacts < 8){
		m_nbrOfContacts++;
	}
}

static bool	areOnlyDigits(std::string str)
{
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

static std::string truncate(std::string const str, size_t width)
{
	if (str.length() > width)
	{
		return (str.substr(0, width - 1) + ".");
	}
	return (str);
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|" 
              << std::setw(10) << "Last name" << "|" 
              << std::setw(10) << "Nickname" << "|";
    std::cout << std::endl;
	for (int i = 0; i < 44; i++)
		std::cout << "-";
	std::cout << std::endl;
    for (int i = 0; i < m_nbrOfContacts; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(m_contacts[i].get_firstName(), 10) << "|";
        std::cout << std::setw(10) << truncate(m_contacts[i].get_lastName(), 10) << "|";
        std::cout << std::setw(10) << truncate(m_contacts[i].get_nickname(), 10) << "|";
        std::cout << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    std::cout << "First name: " << m_contacts[index].get_firstName() << std::endl;
    std::cout << "Last name: " << m_contacts[index].get_lastName() << std::endl;
    std::cout << "Nickname: " << m_contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << m_contacts[index].get_phoneNumber() << std::endl;
    std::cout << "Darkest secret: " << m_contacts[index].get_darkestSecret() << std::endl;
}

int PhoneBook::promptForContact()
{
    std::string input;

    do
    {
        std::cout << std::endl << "Write the index of the contact you want to display (write 'LEAVE' to exit SEARCH command) : ";
        if (std::getline(std::cin, input).eof())
			return 1;
        std::cout << std::endl;
        if (!areOnlyDigits(input))
        {
			if (input != "LEAVE")
            	std::cout << "Bad input, make sure you type a number!" << std::endl;
        }
        else
        {
            int index;
			std::istringstream iss(input);
			if (!(iss >> index)) // extraction of an integer from iss stream
            {
                std::cout << "Bad input, put an index and make sure your number is not too large!" << std::endl;
                continue;
            }
            if (index >= 0 && index < m_nbrOfContacts)
            {
                displayContactDetails(index);
            }
            else
            {
                	std::cout << "Bad input, make sure your index exists!" << std::endl;
            }
        }
    } while (input != "LEAVE");
	return 0;
}

// Add prompt to add a phonebook

int	addPrompt(PhoneBook &phonebook)
{
    std::string fields[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string values[5];

	for (int i = 0; i < 5; i++)
	{
		while (values[i].empty())
		{
			std::cout << fields[i] << ": ";
			//std::cin >> values[i];							<- wait for a non void string
			if (std::getline(std::cin, values[i]).eof())  //	<- take the whole line and take an empty one if it's the case
			{
				return 1;
			}
			if (values[i].empty())
			{
				std::cout << "This field is mandatory!" << std::endl;
			}
		}
	}
	phonebook.addContact(Contact(values[0], values[1], values[2], values[3], values[4]));
	return 0;
}
