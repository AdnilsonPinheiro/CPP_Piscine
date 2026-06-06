#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("RRF", 72, 45), target("Default RRF target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget) :
	AForm("RRF", 72, 45), target(newTarget) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), target(other.target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other){
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeAction()const
{
	static bool	seeded = false;

	if (!seeded){
		std::srand(std::time(NULL));
		seeded = true;
	}
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been successfully robotomized" << std::endl;
	else
		std::cout << "Robotomy failed. Guess not everyday is our lucky day" << std::endl;
}