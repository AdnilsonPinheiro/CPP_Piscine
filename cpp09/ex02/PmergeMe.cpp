#include "PmergeMe.hpp"

static long stoi(const std::string& str);
static int findLoser(const std::vector<std::pair<int, int>>& pairs, int winner);

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
	std::vector< std::pair<int, int> > pairs(num); //pairs[i] = (loser, winner)

	for (size_t i = 0; i < num; i++)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs[i] = std::make_pair(a, b);
	}

	std::vector<int> mainChain;
	
	for (size_t i = 0; i < num; i++)
		mainChain.push_back(pairs[i].second);

	vecFordJohnson(mainChain);

	std::vector<int> jacob = generateJacobsthal(arr.size());

	std::vector<int> order;
	order.push_back(1);

	for (size_t i = 2; i < num; i++)
	{
		size_t hi = std::min(num, (size_t)jacob[i]); //finding the highest point of our batch and preventing overflow
		size_t low = (size_t)jacob[i - 1] + 1; //the lowest point is right after the last jacobsthal index we checked
		for (size_t j = hi; j >= low; j--)
			order.push_back(j);
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

static int findLoser(const std::vector<std::pair<int, int>>& pairs, int winner)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == winner)
			break;
	}
	return (pairs[i].first); 
}

static long stoi(const std::string& str)
{
	long i;
	std::stringstream(str) >> i;
	return i;
}