#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <ctime>
#include <climits>
#include <algorithm>
#include <utility>


    // std::clock_t start;
    // double duration;
    // start = std::clock();
    // duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    // std::cout<<"printf: "<< duration <<'\n';


class PMM
{
private:
	std::vector<int>	vec;
	std::deque<int>		deq;

	std::clock_t		vec_start;
	std::clock_t		deq_start;

	//void displayVector();
	//void displayDeque();

	void vecFordJohnson(std::vector<int>& arr);
	void deqFordJohnson(std::deque<int>& arr);

	std::vector<int> generateVecJacobsthal(size_t n);
	std::deque<int> generateDeqJacobsthal(size_t n);

	template <typename Container>
	void displayContainer(const Container& c);

	template <typename PairContainer>
	int findLoser(const PairContainer& pairs, int winner);

public:
	PMM();
	~PMM();
	PMM(const PMM& src);
	PMM& operator=(const PMM& src);

	void	parseArray(char** argv, int argc);
};

template <typename Container>
void PMM::displayContainer(const Container& c)
{
	if (c.size() > 10)
	{
		typename Container::const_iterator it = c.begin();
		for (size_t i = 0; i < 6; i++, ++it)
			std::cout << *it << " ";
		std::cout << "[...] ";
		typename Container::const_iterator last = c.end();
		--last;
		std::cout << *last << std::endl;
	}
	else
	{
		for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

template <typename PairContainer>
int PMM::findLoser(const PairContainer& pairs, int winner)
{
	typename PairContainer::const_iterator it = pairs.begin();
	while (it != pairs.end())
	{
		if (it->second == winner)
			return it->first;
		++it;
	}
	return winner;
}

#endif