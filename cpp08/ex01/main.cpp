#include "Span.hpp"

int main()
{
	std::cout << "\n=== [SUBJECT EXAMPLE] ===\n" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n=== [MY TESTS] ===\n" << std::endl;
	std::cout << "[OVERFLOW CONTAINER]" << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n[CONTAINER TOO SMALL]\n" << std::endl;

	Span sp2(2);

	sp2.addNumber(1);

	try
	{
		sp2.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		sp2.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n===[20.000 RANDOM NUMBERS]===\n" << std::endl;

	Span mega(20000);

	mega.addRandomNumbers(20000);

	try
	{
		std::cout << "Trying to add even more numbers" << std::endl;
		mega.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << mega.shortestSpan() << std::endl;
	std::cout << mega.longestSpan() << std::endl;

	return 0;
}