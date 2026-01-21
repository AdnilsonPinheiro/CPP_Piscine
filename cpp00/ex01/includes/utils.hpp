#ifndef UTILS_HPP
# define UTILS_HPP

# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <iomanip>
# include <sstream>


int			buildContact(Contact *newContact);
int	my_stoi(std::string &input);

void		ft_search(PhoneBook *PhoneBook);
void		DisplayContacts(PhoneBook *pb);
void		DisplayDetails(Contact contact);

std::string	fix_width(std::string str);

#endif