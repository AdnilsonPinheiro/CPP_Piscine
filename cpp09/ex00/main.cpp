#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
		throw std::runtime_error("Error: invalid number of arguments");
	try
	{
		BitcoinExchange btc;
		btc.processInput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}