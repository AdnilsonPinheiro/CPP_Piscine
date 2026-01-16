#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	darkest_secret;
		std::string	phone_number;

	public:
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickName() const;
		std::string	getSecret() const;
		std::string	getNumber() const;

		int			setFirstName();
		int			setLastName();
		int			setNickName();
		int			setSecret();
		int			setNumber();
		
		Contact();
		~Contact();
};

#endif