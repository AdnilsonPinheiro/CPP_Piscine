#include "../includes/utils.hpp"

int	buildContact(Contact *newContact){
	if (newContact->setFirstName())
		return 1;
	if (newContact->setLastName())
		return 1;
	if (newContact->setNickName())
		return 1;
	if (newContact->setSecret())
		return 1;
	if (newContact->setNumber())
		return 1;
	return 0;
}

void	ft_search(PhoneBook *PhoneBook){
	std::string	input;
	int	num;


	DisplayContacts(PhoneBook);
	std::cout << "Which contact would you like to see?" << std::endl;
	std::getline(std::cin, input);
	num = ft_atoi(input);
	if (num < 0)
	{
		std::cout << "Invalid number, sorry." << std::endl;
		return ;
	}
	if (num >= PhoneBook->getCount())
	{
		std::cout << "We don't have that many friends." << std::endl;
		return ;
	}
	DisplayDetails(PhoneBook->getContactData(num));
}

void	DisplayContacts(PhoneBook *pb){
	for (int index = 0; index < pb->getCount(); index++){
		std::cout << std::setw(10) << std::right << index;
		std::cout << "|" << std::setw(10) << std::right << fix_width(pb->getContactData(index).getFirstName());
		std::cout << "|" << std::setw(10) << std::right << fix_width(pb->getContactData(index).getLastName());
		std::cout << "|" << std::setw(10) << std::right << fix_width(pb->getContactData(index).getNickName());
		std::cout << std::endl;
	}
}

void	DisplayDetails(Contact contact){
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nick name: " << contact.getNickName() << std::endl;
	std::cout << "Phone number: " << contact.getNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

std::string	fix_width(std::string str){
	if (str.length() > 10){
		return (str.substr(0, 9) + ".");
	}
	return str;
}

int	ft_atoi(std::string input){
	int	num;
	size_t	i;

	if (input.empty())
		return -1;
	for (i = 0; i < input.length(); i++){
		if (input[i] < '0' || input[i] > '9')
			return (-1);
	}
	num = 0;
	for (i = 0; i < input.length(); i++){
		num = (num * 10) + (input[i] - 48);
	}
	return (num);
}