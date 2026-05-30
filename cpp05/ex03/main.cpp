#include "inc/Bureaucrat.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/Intern.hpp"

int	main()
{
	Intern	someIntern;
	AForm*	rrf;

	rrf = someIntern.makeForm("robotomy request", "Bender");

	std::cout << rrf->getName() << std::endl;

	return 0;
}