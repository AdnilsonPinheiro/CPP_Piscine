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

	void displayVector();
	void vecFordJohnson(std::vector<int>& arr);

	std::vector<int> generateJacobsthal(size_t n);

public:
	PMM();
	~PMM();
	PMM(const PMM& src);
	PMM& operator=(const PMM& src);

	void	parseArray(char** argv, int argc);
};

#endif