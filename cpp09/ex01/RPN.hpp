#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	int evaluate(const std::string& expression);
};