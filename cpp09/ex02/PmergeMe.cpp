#include "PmergeMe.hpp"

PMM::PMM() {}
PMM::~PMM() {}
PMM::PMM(const PMM& src) : vect(src.vect), deq(src.deq) {}
PMM& PMM::operator=(const PMM& src)
{
	if (this != &src)
	{
		this->vect = src.vect;
		this->deq = src.deq;
	}
	return (*this);
}

void PMM::parseArray(char** argv, int argc)
{
	int j;
	// begin measuring time
	for (int i = 0; i < argc - 1; i++)
	{
		std::string str(argv[i + 1]);
		for (size_t len = 0; len < str.length(); len++)
		{
			if (!isdigit(str[len]))
				throw std::runtime_error("Error: Arguments must be numbers");
		}
		j = stoi(str);
		if (j < 0)
			throw std::runtime_error("Error: numbers must be positive");
		this->vect.push_back(j);
		this->deq.push_back(j);
	}
}

int stoi(const std::string& str)
{
	int i;
	std::stringstream(str) >> i;
	return i;
}