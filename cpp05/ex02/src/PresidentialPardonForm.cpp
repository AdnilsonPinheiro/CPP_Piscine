#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Pardon Form", 25, 5), target("Standard Pardon Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string newTarget) :
	AForm("Pardon Form", 25, 5), target(newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other), target(other.target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other){
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::executeAction()const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}