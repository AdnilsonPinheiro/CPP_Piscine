#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>

int main()
{
	std::cout << "\n=====[INT STACK]=====\n" << std::endl;

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n=====[LIST STACK]=====\n" << std::endl;

	std::list<int>	lstack;

	lstack.push_back(5);
	lstack.push_back(17);

	std::cout << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	lstack.push_back(0);

	std::list<int>::iterator lt = lstack.begin();
	std::list<int>::iterator lte = lstack.end();

	++lt;
	--lt;
	while (lt != lte)
	{
		std::cout << *lt << std::endl;
		++lt;
	}

	std::cout << "\n=====[VECTOR STACK]=====\n" << std::endl;

	std::vector<int>	vstack;

	vstack.push_back(5);
	vstack.push_back(17);

	std::cout << vstack.back() << std::endl;

	vstack.pop_back();

	std::cout << vstack.size() << std::endl;

	vstack.push_back(3);
	vstack.push_back(5);
	vstack.push_back(737);
	vstack.push_back(0);

	std::vector<int>::iterator vt = vstack.begin();
	std::vector<int>::iterator vte = vstack.end();

	++vt;
	--vt;
	while (vt != vte)
	{
		std::cout << *vt << std::endl;
		++vt;
	}

	std::cout << "\n=====[DEQUE STACK]=====\n" << std::endl;

	std::deque<int>	dstack;

	dstack.push_back(5);
	dstack.push_back(17);

	std::cout << dstack.back() << std::endl;

	dstack.pop_back();

	std::cout << dstack.size() << std::endl;

	dstack.push_back(3);
	dstack.push_back(5);
	dstack.push_back(737);
	dstack.push_back(0);

	std::deque<int>::iterator dt = dstack.begin();
	std::deque<int>::iterator dte = dstack.end();

	++dt;
	--dt;
	while (dt != dte)
	{
		std::cout << *dt << std::endl;
		++dt;
	}

	return 0;
}