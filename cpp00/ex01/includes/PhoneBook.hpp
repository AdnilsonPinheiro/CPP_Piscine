#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

# define MAX_CONTACTS 9

class PhoneBook{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		num_contacts;
	public:
		void	add(Contact);
		void	search();
		PhoneBook(Contact new_contact);
		~PhoneBook();
};

#endif