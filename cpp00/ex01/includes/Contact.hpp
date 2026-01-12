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

		void		setFirstName(const std::string &first_name);
		void		setLastName(const std::string &last_name);
		void		setNickName(const std::string &nick_name);
		void		setSecret(const std::string &secret);
		void		setNumber(const std::string &number);
		
		Contact();
		~Contact();
};

#endif