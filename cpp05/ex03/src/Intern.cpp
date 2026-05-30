#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {(void)other;}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}
Intern::~Intern(){}

static AForm*	createPresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	createRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	createShrubberyCreationFrom(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string form, const std::string target)const
{
	const std::string	formList[3] =
		{"presidential pardon", "robotomy request", "shrubbery creation"};
	
	AForm* (*formFunctions[3])(const std::string&) = 
		{&createPresidentialPardonForm, 
		&createRobotomyRequestForm, 
		&createShrubberyCreationFrom};

	for (int i = 0; i < 3; i++){
		if (form == formList[i])
			return (formFunctions[i](target));
	}

	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("There's no such form");
}
