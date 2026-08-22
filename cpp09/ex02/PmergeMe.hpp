#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <stdlib.h>

class PMM
{
private:
	std::vector<int>	vect;
	std::deque<int>		deq;

	int stoi(const std::string& str);

	template<typename T>
	void	generateJacobsthal(int n, T& container)
	{
		T.push_back(0);
		T.push_back(1);
		T.push_back(3);

		for (size_t i = 3; i < n; i++)
		{
			container::iterator it = container.end();
			--it;
			int last = *it;
			--it;
			int secondLast = *it;
			int newElement = last + (2* secondLast);
			container.push_back(newElement);
		}
	}

	template<typename T>
	void displayArray(T arr)
	{
		if (arr.lenght() > 10)
		{
			for (size_t i = 0; i < 6; i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << "[...] "
			std::cout << arr[arr.length() - 1] << std::endl;
		}
		else
		{
			for (size_t i = 0; i < arr.length(); i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << std::endl;
		}
	}

public:
	PMM();
	~PMM();
	PMM(const PMM& src);
	PMM& operator=(const PMM& src);

	void	parseArray(char** argv, int argc);
};

#endif