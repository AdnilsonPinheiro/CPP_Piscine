#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>

static void impossible()
{
    std::cout << "impossible" << std::endl;
}

static void non_disp()
{
    std::cout << "Non displayable" << std::endl;
}

static bool is_neg_inf(const std::string& input)
{
    if (input == "-inf" || input == "-inff")
        return true;
    return false;
}

static bool is_pos_inf(const std::string& input)
{
    if (input == "+inf" || input == "+inff" || input == "inf")
        return true;
    return false;
}

static bool is_nan(const std::string& input)
{
    if (input == "nan" || input == "nanf")
        return true;
    return false;
}

static void printChar(const std::string& input)
{
    std::cout << "char: ";
    if (is_nan(input) || is_neg_inf(input) || is_pos_inf(input))
        return impossible();
    long int nbr = std::strtol(input.c_str(), NULL, 10);
    if (nbr < 0 || nbr > 127)
        impossible();
    else if (nbr > 32 && nbr < 127)
        std::cout << static_cast<char>(nbr) << std::endl;
    else if ((nbr < 33 && nbr >= 0) || nbr == 127)
        non_disp();
}

// static void printInt(std::string& input)
// {

// }

// static void printFloat(std::string& input)
// {

// }

// static void printDouble(std::string& input)
// {

// }

void ScalarConverter::convert(const std::string& input)
{
    printChar(input);
}
