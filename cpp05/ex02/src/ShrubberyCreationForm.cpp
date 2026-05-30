#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : 
	AForm("Shrubbery Creation Form", 145, 137), target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string newTarget) :
	AForm("Shrubbery Creation Form", 145, 137), target(newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
	AForm(other), target(other.target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction()const
{
	std::string	filename = this->target + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	if (!outfile.is_open())
		throw std::logic_error("Error opening outfile");
	std::cout << "Check your ls again ;)" << std::endl;
	outfile <<
		"    * \n" <<
		"   /.\\ \n" <<
		"  /o..\\ \n" <<
		"  /..o\\ \n" <<
		" /.o..o\\ \n" <<
		" /...o.\\ \n" <<
		"/..o....\\ \n" <<
		"^^^[_]^^^ \n";
	outfile.close();
}