#include "PmergeMe.hpp"

static long stoi(const std::string& str);

PMM::PMM() {}
PMM::~PMM() {}
PMM::PMM(const PMM& src) : vec(src.vec), deq(src.deq) {}
PMM& PMM::operator=(const PMM& src)
{
	if (this != &src)
	{
		vec = src.vec;
		deq = src.deq;
	}
	return (*this);
}

void PMM::parseArray(char** argv, int argc)
{
	long j;

	for (int i = 0; i < argc - 1; i++)
	{
		std::string str(argv[i + 1]);
		for (size_t len = 0; len < str.length(); len++)
		{
			if (!isdigit(str[len]))
				throw std::runtime_error("Error: Arguments must be positive numbers");
		}
		j = stoi(str);
		if (j < 0 || j > INT_MAX)
			throw std::runtime_error("Error: numbers must be within [0, INT_MAX]");
		vec.push_back(j);
		deq.push_back(j);
	}

	std::cout << "Before: ";
	displayVector();

	vec_start = std::clock();
	vecFordJohnson(vec);

	//std::cout << "After: ";
	//displayVector();
}

void PMM::displayVector()
{
	if (vec.size() > 10)
	{
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << vec[i] << " ";
		}
		std::cout << "[...] ";
		std::vector<int>::iterator it = vec.end();
		--it;
		std::cout << *it << std::endl;
	}
	else
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl;
	}
}

void PMM::vecFordJohnson(std::vector<int>& arr)
{
	if (arr.size() < 2)
		return;

	bool has_trailer = false;
	int trailer;

	if (arr.size() % 2 != 0)
	{
		has_trailer = !has_trailer;
		trailer = arr.back();
		arr.pop_back();
	}

	size_t num = arr.size()/2;
	std::vector<int> pairs[num];

	size_t i = 0;
	size_t j = 0;
	while (i < arr.size() && j < num)
	{
		pairs[j].push_back(arr[i]);
		pairs[j].push_back(arr[i+1]);
		std::sort(pairs[j].begin(), pairs[j].end());
		i += 2;
		j++;
	}

	std::vector<int> mainChain;
	for (size_t i = 0; i < num; i++)
	{
		mainChain.push_back(pairs[i].back());
		std::sort(mainChain.begin(), mainChain.end());
	}

	vecFordJohnson(mainChain);

	std::vector<int> jacob = generateJacobsthal(arr.size());

	for (size_t i = 0; i < jacob.size(); i++)
	{
		int value;
		int idx = jacob[i];
		int upperLimit = mainChain.at(idx);
		if (i == 0)
		{
			value = pairs[i].front();
			mainChain.insert(0, value);
		}	
		else
		{
			int lowerLimit = jacob[i - 1];
			int newIdx = idx - 1;
			while (newIdx > lowerLimit)
			{
				value  = pairs[newIdx].front();
				
				newIdx--;
			}
		}
	}

	if (has_trailer)
		(void)trailer;
}


std::vector<int> PMM::generateJacobsthal(size_t n)
{
	std::vector<int> jacob;

	jacob.push_back(0);
	jacob.push_back(1);
	jacob.push_back(3);

	for (size_t i = 3; i < n; i++)
	{
		std::vector<int>::iterator it = jacob.end();
		--it;
		int last = *it;
		--it;
		int secondLast = *it;
		jacob.push_back(last + (2*secondLast));
	}
	return jacob;
}

static long stoi(const std::string& str)
{
	long i;
	std::stringstream(str) >> i;
	return i;
}