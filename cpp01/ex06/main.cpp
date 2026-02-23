#include "includes/Harl.hpp"

int	getCase(std::string &input)
{
	std::string	cases[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	for (int i = 0; i < 4; i++){
		if (input.compare(cases[i]) == 0){
			return i;
		}
	}
	return -1;
}

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "USAGE ./harlFilter arg" << std::endl;
		std::cout << "Options for arg\n\t[DEBUG]\n\t[INFO]\n\t[WARNING]\n\t[ERROR]" << std::endl;
		return 0;
	}
	else {
		Harl harl;
		std::string	input;
		std::getline(std::cin, input);
		int	caseNum = getCase(input);
		switch(caseNum){
			case 1:
				harl.debug();
			case 2:
				harl.info();
			case 3:
				harl.warning();
			case 4:
				harl.error();
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break ;
		}
		return 0;
	}
}