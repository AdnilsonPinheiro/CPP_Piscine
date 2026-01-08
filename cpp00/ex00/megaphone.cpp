#include <iostream>

int	main(int argc, char **argv){
	if (argc != 1){
		std::string	line;
		for (int i = 1; i < argc; i++){
			line += argv[i];
		}
		for (size_t i = 0; i < line.length(); i++){
			line[i] = std::toupper(line[i]);
		}
		std::cout << line << std::endl;
	}
	else{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}
