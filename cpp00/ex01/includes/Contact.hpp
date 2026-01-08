#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		std::string	phone_number;

	public:
		Contact(std::string first_name, std::string last_name, std::string nick_name, \
							std::string darkest_secret, std::string phone_number);
		Contact();
		~Contact();
};

#endif