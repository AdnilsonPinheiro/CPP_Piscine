#include "../includes/Contact.hpp"

/*Getter Functions*/
std::string	Contact::getFirstName() const{
	return first_name;
}

std::string	Contact::getLastName() const{
	return last_name;
}

std::string	Contact::getNickName() const{
	return nick_name;
}

std::string	Contact::getSecret() const{
	return darkest_secret;
}

std::string	Contact::getNumber() const{
	return phone_number;
}

/*Setter Functions*/
int	Contact::setFirstName(){
	std::string	input;
	std::cout << "Please enter the contact's first name" << std::endl;
	std::getline(std::cin, input);
	if (input.length() < 1)
		return 1;
	this->first_name = input;
	return 0;
}

int	Contact::setLastName(){
	std::string	input;
	std::cout << "Please enter the contact's last name" << std::endl;
	std::getline(std::cin, input);
	if (input.length() < 1)
		return 1;
	this->last_name = input;
	return 0;
}

int	Contact::setNickName(){
	std::string	input;
	std::cout << "Please enter the contact's nick name" << std::endl;
	std::getline(std::cin, input);
	if (input.length() < 1)
		return 1;
	this->nick_name = input;
	return 0;
}

int	Contact::setSecret(){
	std::string	input;
	std::cout << "Please enter the contact's darkest secret" << std::endl;
	std::getline(std::cin, input);
	if (input.length() < 1)
		return 1;
	this->darkest_secret = input;
	return 0;
}

int	Contact::setNumber(){
	std::string	input;
	std::cout << "Please enter the contact's number" << std::endl;
	std::getline(std::cin, input);
	if (input.length() < 1)
		return 1;
	for (size_t i = 0; i < input.length(); i++){
		if (!isdigit(input[i])){
			std::cout << "Phone number should (obvisouly) just contain numbers" << std::endl;
			return 1;
		}
	}
	this->phone_number = input;
	return 0;
}

/*Constructor*/
Contact::Contact(){}

/*Destructor*/
Contact::~Contact(){}