#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string	target;
protected:
	void	executeAction(void)const;
public:
	RobotomyRequestForm		();
	RobotomyRequestForm		(std::string newTarget);
	RobotomyRequestForm		(const RobotomyRequestForm& other);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm	();
};

#endif