#include "PmergeMe.hpp"

static long stoi(const std::string& str);
//static int vecFindLoser(const std::vector<std::pair<int, int> >& pairs, int winner);
//static int deqFindLoser(const std::deque<std::pair<int, int> >& pairs, int winner);

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
	//displayVector();
	displayContainer(vec);

	vec_start = std::clock();
	vecFordJohnson(vec);
	std::clock_t vec_end = std::clock();
	double vec_time = static_cast<double>(vec_end - vec_start) / (double)CLOCKS_PER_SEC * 1000000.0;

	deq_start = std::clock();
	deqFordJohnson(deq);
	std::clock_t deq_end = std::clock();
	double deq_time = static_cast<double>(deq_end - deq_start) / (double)CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	//displayVector();
	displayContainer(vec);

	std::cout << "\nTime elapsed to process "<< vec.size() <<" elements on VECTOR:\t" << vec_time << "us" << std::endl;
	std::cout << "Time elapsed to process "<< deq.size() <<" elements on DEQUE:\t\t" << deq_time << "us" << std::endl;
}

/*************************************************************************************/
/************************ Vector Implementation **************************************/
/*************************************************************************************/

/*void PMM::displayVector()
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
}*/

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

	std::vector<int> jacob = generateVecJacobsthal(arr.size());

	std::vector<int> order;
	order.push_back(1);

	for (size_t i = 2; i < jacob.size(); i++)
	{
		size_t upper = std::min(num, (size_t)jacob[i]); //finding the highest point of our batch and preventing overflow
		size_t bottom = (size_t)jacob[i - 1] + 1; //the lowest point is right after the last jacobsthal index we checked
		for (size_t j = upper; j >= bottom; j--)
			order.push_back(j);
		if ((size_t)jacob[i] >= num) //avoid overflowing
			break;
	}

	// Tests order of insertion
	// std::cout << "Order of insertion: ";
	// for (size_t i = 0; i < order.size(); i++)
	// 	std::cout << order[i] << " ";
	// std::cout << std::endl;

	//Insert losers from pairs into the mainchain
	for (size_t idx = 0; idx < order.size(); idx++)
	{
		size_t i = order[idx];
		int win = pairs[i - 1].second;
		int los = findLoser(pairs, win);

		std::vector<int>::iterator posWin = std::find(mainChain.begin(), mainChain.end(), win);
		std::vector<int>::iterator insertPos = std::upper_bound(mainChain.begin(), posWin, los);

		mainChain.insert(insertPos, los);
	}

	//Insert trailling element
	if (has_trailer)
	{
		std::vector<int>::iterator insertPos = std::upper_bound(mainChain.begin(), mainChain.end(), trailer);
		mainChain.insert(insertPos, trailer);
	}

	arr = mainChain;
}


std::vector<int> PMM::generateVecJacobsthal(size_t n)
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

/*************************************************************************************/
/************************* Deque Implementation **************************************/
/*************************************************************************************/

/*void PMM::displayDeque()
{
	if (deq.size() > 10)
	{
		for (size_t i = 0; i < 6; i++)
		{
			std::cout << deq[i] << " ";
		}
		std::cout << "[...] ";
		std::deque<int>::iterator it = deq.end();
		--it;
		std::cout << *it << std::endl;
	}
	else
	{
		for (size_t i = 0; i < deq.size(); i++)
		{
			std::cout << deq[i] << " ";
		}
		std::cout << std::endl;
	}
}*/

void PMM::deqFordJohnson(std::deque<int>& arr)
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
	std::deque< std::pair<int, int> > pairs(num); //pairs[i] = (loser, winner)

	for (size_t i = 0; i < num; i++)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a > b)
			std::swap(a, b);
		pairs[i] = std::make_pair(a, b);
	}

	std::deque<int> mainChain;
	
	for (size_t i = 0; i < num; i++)
		mainChain.push_back(pairs[i].second);

	deqFordJohnson(mainChain);

	std::deque<int> jacob = generateDeqJacobsthal(arr.size());

	std::deque<int> order;
	order.push_back(1);

	for (size_t i = 2; i < jacob.size(); i++)
	{
		size_t upper = std::min(num, (size_t)jacob[i]);
		size_t bottom = (size_t)jacob[i - 1] + 1;
		for (size_t j = upper; j >= bottom; j--)
			order.push_back(j);
		if ((size_t)jacob[i] >= num)
			break;
	}

	for (size_t idx = 0; idx < order.size(); idx++)
	{
		size_t i = order[idx];
		int win = pairs[i - 1].second;
		int los = findLoser(pairs, win);

		std::deque<int>::iterator posWin = std::find(mainChain.begin(), mainChain.end(), win);
		std::deque<int>::iterator insertPos = std::upper_bound(mainChain.begin(), posWin, los);

		mainChain.insert(insertPos, los);
	}

	if (has_trailer)
	{
		std::deque<int>::iterator insertPos = std::upper_bound(mainChain.begin(), mainChain.end(), trailer);
		mainChain.insert(insertPos, trailer);
	}

	arr = mainChain;
}


std::deque<int> PMM::generateDeqJacobsthal(size_t n)
{
	std::deque<int> jacob;

	jacob.push_back(0);
	jacob.push_back(1);
	jacob.push_back(3);

	for (size_t i = 3; i < n; i++)
	{
		std::deque<int>::iterator it = jacob.end();
		--it;
		int last = *it;
		--it;
		int secondLast = *it;
		jacob.push_back(last + (2*secondLast));
	}
	return jacob;
}

/*************************************************************************************/
/************************************** Utils ****************************************/
/*************************************************************************************/

/*static int vecFindLoser(const std::vector<std::pair<int, int> >& pairs, int winner)
{
	size_t i = 0;

	while (i < pairs.size())
	{
		if (pairs[i].second == winner)
			break;
		i++;
	}
	return (pairs[i].first); 
}

static int deqFindLoser(const std::deque<std::pair<int, int> >& pairs, int winner)
{
	size_t i = 0;

	while (i < pairs.size())
	{
		if (pairs[i].second == winner)
			break;
		i++;
	}
	return (pairs[i].first); 
}*/

static long stoi(const std::string& str)
{
	long i;
	std::stringstream(str) >> i;
	return i;
}