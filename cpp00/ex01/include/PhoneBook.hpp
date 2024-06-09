#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	addContact(Contact contact);
		void	displayContacts() const;
		void	promptForContact();
		~PhoneBook();
	private:
		Contact m_contacts[8];
		int		m_nbrOfContacts;
		void	displayContactDetails(int index) const;
};

void	addPrompt(PhoneBook &phonebook);

#endif