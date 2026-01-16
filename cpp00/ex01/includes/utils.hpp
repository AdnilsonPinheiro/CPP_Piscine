#ifndef UTILS_HPP
# define UTILS_HPP

# include "PhoneBook.hpp"
# include "Contact.hpp"
# include <iomanip>

int			buildContact(Contact *newContact);
int			ft_atoi(std::string input);

void		ft_search(PhoneBook *PhoneBook);
void		DisplayContacts(PhoneBook *pb);
void		DisplayDetails(Contact contact);

std::string	fix_width(std::string str);

#endif