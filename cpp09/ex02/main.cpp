#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: program needs at least two arguments" << std::endl;
		return 1;
	}
	else
	{
		PMM merge;
		try
		{
			merge.parseArray(argv, argc);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		return 0;
	}
}