#include "../includes/Harl.hpp"

Harl::Harl(void){}

void	Harl::debug(void)
{
	std::cout << "This is a DEBUG level comment! Debug it! Now!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "This is an INFO level comment, which means you need to read some more." << std::endl	;
}

void	Harl::warning(void)
{
	std::cout << "This is a WARNING! I'm warning you!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is an ERROR message, which means something unacceptable has probably happened. Be better." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	complaintLevel[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	void	(Harl::*complaintFunction[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++){
		if (level.compare(complaintLevel[i]) == 0){
			(this->*complaintFunction[i])();
		}
	}
}

Harl::~Harl(void){}