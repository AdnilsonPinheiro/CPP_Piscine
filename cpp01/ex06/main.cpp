#include "includes/Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2){
		if (argc == 1){
			std::cout << "[ It needs something to complain about ]" << std::endl;
		}
		else {
			std::cout << "[ Complaints should be done one at a time ]" << std::endl;
		}
		return 0;
	}
	else {
		Harl		harl;
		std::string	args = argv[1];
		harl.complain(args);
		return 0;
	}
}