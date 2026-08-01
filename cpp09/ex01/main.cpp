#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		int result = rpn.evaluate(argv[1]);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return 2;
	}
	return 0;
}