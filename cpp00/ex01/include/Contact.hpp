#ifndef Contact_hpp
#define Contact_hpp

#include <string>

class Contact
{
	public:
		Contact();
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		std::string	get_firstName() const;
		std::string	get_lastName() const;
		std::string	get_nickname() const;
		std::string	get_phoneNumber() const;
		std::string	get_darkestSecret() const;
		~Contact();
	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickname;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
};

#endif