#include "Span.hpp"
#include <ctime>

Span::Span(unsigned int N) : N(N) {}
Span::Span(const Span& src) : N(src.N), data(src.data) {}
Span::~Span() {}
Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->N = src.N;
		for (size_t i = 0; i < src.data.size(); i++)
			this->data[i] = src.data[i];
	}
	return *this;
}

void	Span::addNumber(int value)
{
	if (data.size() >= N)
		throw fullException();
	data.push_back(value);
	std::cout << "Value: " << value << " added to container." << std::endl;
}
unsigned int	Span::shortestSpan()const
{
	if (data.size() < 2)
		throw emptyException();
	std::vector<int> copy = data;
	int num = abs(copy[0] - copy[1]);
	for (size_t i = 0; i < copy.size(); i++)
	{
		if (i + 1 < copy.size())
		{
			if (abs(copy[i] - copy[i + 1]) < num)
				num = abs(copy[i] - copy[i + 1]);
		}
	}
	return num;
}
unsigned int	Span::longestSpan()const
{
	if (data.size() < 2)
		throw emptyException();
	std::vector<int> copy = data;
	std::sort(copy.begin(), copy.end());
	return (abs(copy.front() - copy.back()));
}
void	Span::addRandomNumbers(unsigned int amount)
{
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	for (unsigned int i = 0; i < amount; i++)
	{
		try
		{
			addNumber(std::rand());
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}