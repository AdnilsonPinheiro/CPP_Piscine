#include "Contact.hpp"

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
void	Contact::setFirstName(const std::string &first_name){
	this->first_name = first_name;
}

void	Contact::setLastName(const std::string &last_name){
	this->last_name = last_name;
}

void	Contact::setNickName(const std::string &nick_name){
	this->nick_name = nick_name;
}

void	Contact::setSecret(const std::string &secret){
	this->darkest_secret = secret;
}

void	Contact::setNumber(const std::string &number){
	for (size_t i = 0; i < number.length(); i++){
		if (!isdigit(number[i])){
			std::cout << "Phone number should (obvisouly) just contain numbers" << std::endl;
			return ;
		}
	}
	this->phone_number = number;
}

/*Constructor*/
Contact::Contact(){}

/*Destructor*/
Contact::~Contact(){}