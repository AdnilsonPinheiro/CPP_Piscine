/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpinhei <adpinhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:03:54 by adpinhei          #+#    #+#             */
/*   Updated: 2026/01/20 17:55:07 by adpinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/utils.hpp"
#include <cstdlib>

int	main(){
	PhoneBook	PhoneBook;
	std::string	input;
	bool		noContacts = true;

	while (std::cin.eof() == false){
		std::cout << "Enter command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("EXIT") || !input.compare("exit"))
			return 0;
		else if (!input.compare("ADD") || !input.compare("add")){
			Contact		newContact;
			if (buildContact(&newContact))
			{
				std::cout << "Contacts cannot have empty fields." << std::endl;
				continue ;
			}
			PhoneBook.setNewContact(newContact);
			noContacts = false;
		}
		else if (!input.compare("SEARCH") || !input.compare("search"))
		{
			if (noContacts){
				std::cout << "No contacts to display." << std::endl;
				continue ;
			}
			ft_search(&PhoneBook);
		}
		else
			continue ;
	}
}