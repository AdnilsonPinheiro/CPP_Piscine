#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	target;
protected:
	void	executeAction(void)const;
public:
	ShrubberyCreationForm	();
	ShrubberyCreationForm	(const std::string newTarget);
	ShrubberyCreationForm	(const ShrubberyCreationForm& other);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm	();
};

#endif