#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	addContact(Contact contact);
		void	showContacts() const;
		~PhoneBook();
	private:
		Contact m_contacts[8];
		int		m_nbrOfContacts;
};

bool	areOnlyNumbers(std::string str);

#endif