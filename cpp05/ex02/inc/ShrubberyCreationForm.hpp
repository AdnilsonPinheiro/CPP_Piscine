#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	target;
protected:
	void	executeAction(void)const;
public:
	ShrubberyCreationForm	();
	ShrubberyCreationForm	(const std::string newName);
	ShrubberyCreationForm	(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm	();
};

#endif