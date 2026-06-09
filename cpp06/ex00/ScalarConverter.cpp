#include "ScalarConverter.hpp"
#include <cstdlib>

static void impossible()
{
    std::cout << "impossible" << std::endl;
}

static void printChar(std::string& input)
{
    char c = input [0];
    if (input.length() == 1 && (c > 32 && c < 127))
        std::cout << input << std::endl;
    else
        impossible();
}

static void printInt(std::string& input)
{
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
        return (impossible());
    int nbr = atoi(input.c_str());
}

static void printFloat(std::string& input)
{

}

static void printDouble(std::string& input)
{

}

void ScalarConverter::convert(std::string& input)
{

}
