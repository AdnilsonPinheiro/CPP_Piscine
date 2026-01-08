#include "PhoneBook.hpp"

void	PhoneBook::add(Contact new_contact){
	if (this->num_contacts > MAX_CONTACTS)
		this->num_contacts = 1;
	this->contacts[num_contacts] = new_contact;
}

void	PhoneBook::search(){

}

PhoneBook::PhoneBook(Contact new_contact){
	this->num_contacts = 0;
}

PhoneBook::~PhoneBook(){

}