#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <string>

# define MAX_CONTACTS 8
# define COLUMN_WIDTH 10

class PhoneBook{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		index;
		int		lastContact;

	public:
		void				setNewContact(const Contact &new_contact);
		const Contact		&getContactData(int index) const;

		PhoneBook();
		~PhoneBook();
};

#endif