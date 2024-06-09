#include "../include/Contact.hpp"
#include <string>

Contact::Contact() : m_firstName(""), m_lastName(""), m_nickname(""), m_phoneNumber(""), m_darkestSecret("") {}
Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phoneNumber, std::string darkestSecret) : m_firstName(firstname), m_lastName(lastname), m_nickname(nickname), m_phoneNumber(phoneNumber), m_darkestSecret(darkestSecret) {}
Contact::~Contact() {}

std::string	Contact::get_firstName() const
{
	return(m_firstName);
}

std::string	Contact::get_lastName() const
{
	return(m_lastName);
}

std::string	Contact::get_nickname() const
{
	return(m_nickname);
}

std::string	Contact::get_phoneNumber() const
{
	return (m_phoneNumber);
}

std::string	Contact::get_darkestSecret() const
{
	return (m_darkestSecret);
}