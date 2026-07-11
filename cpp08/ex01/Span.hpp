#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
	unsigned int		N;
	std::vector<int>	data;
public:
	Span(unsigned int N);
	Span(const Span& src);
	~Span();
	Span& operator=(const Span& src);

	void 			addNumber(int value);
	unsigned int	shortestSpan()const;
	unsigned int	longestSpan()const;
	void			addRandomNumbers(unsigned int amount);

	class fullException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "No more elements can be added. Container is full.\n";
			}
	};
	class emptyException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "At least two values must be added to the container.\n";
			}
	};
};

#endif