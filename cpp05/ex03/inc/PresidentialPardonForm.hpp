#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string	target;
protected:
	void	executeAction(void)const;
public:
	PresidentialPardonForm	();
	PresidentialPardonForm	(const std::string newTarget);
	PresidentialPardonForm	(const PresidentialPardonForm& other);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm	();
};

#endif