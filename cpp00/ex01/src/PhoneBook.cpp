#include "PhoneBook.hpp"

void PhoneBook::setNewContact(const Contact &new_contact){
	this->contacts[this->index % MAX_CONTACTS] = new_contact;
	this->index++;
	if (this->lastContact < MAX_CONTACTS)
		this->lastContact++;
}

const Contact	&PhoneBook::getContactData(int index) const{
	return this->contacts[index];
}

/*Constructor*/
PhoneBook::PhoneBook(): index(0), lastContact(0) {}

/*Destructor*/
PhoneBook::~PhoneBook(){}