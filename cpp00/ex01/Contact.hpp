#include "AwesomePhoneBook.hpp"

class Contact{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		int			phone_number;
		int			index;

	public:
		Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, \
		std::string darkest_secret, int phone_number);
		Contact::~Contact();
};
