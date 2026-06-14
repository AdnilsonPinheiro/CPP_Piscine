#include "ScalarConverter.hpp"

static int inputType(const std::string& str);
static void printFromChar(const char c);
static void printFromInt(const std::string& str);
static void printFromFloat(const std::string& str);
static void printFromDouble(const std::string& str);
static void printFromPseudo(const std::string &str);

void ScalarConverter::convert(const std::string& input)
{
    int t = inputType(input);
    switch(t)
    {
        case CHAR:
            printFromChar(input[0]);
            break;
        case INT:
            printFromInt(input);
            break;
        case FLOAT:
            printFromFloat(input);
            break;
        case DOUBLE:
            printFromDouble(input);
            break;
        case PSEUDO:
            printFromPseudo(input);
            break;
        case ERROR:
            std::cerr << "Invalid argument. Must represent a C++ literal" << std::endl;
    }
}

static int inputType(const std::string& str)
{
    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || \
        str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return PSEUDO;
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;

    char* endPtr;
    long n;

    n = std::strtol(str.c_str(), &endPtr, 10);
    if (*endPtr == '\0' && n >= INT_MIN && n <= INT_MAX)
        return INT;
    std::strtof(str.c_str(), &endPtr);
    if (*endPtr == 'f' && *(endPtr + 1) == '\0')
        return FLOAT;
    std::strtod(str.c_str(), &endPtr);
    if (*endPtr == '\0')
        return DOUBLE;
    return ERROR;
}

static void printFromChar(const char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void printFromInt(const std::string& str)
{
    int n = static_cast<int>(std::strtol(str.c_str(), NULL, 10));

    if (n >= 0 && n <= 127)
    {
        if (std::isprint(n))
            std::cout << "char: '" << static_cast<char>(n) << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    std::cout << "int: " << n << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(n) << "f\n";
    std::cout << "double: " << static_cast<double>(n) << std::endl;
}

static void printFromFloat(const std::string& str)
{
    float n = std::atof(str.c_str());

    if (n >= 0 && n <= 127)
    {
        if (std::isprint(n))
            std::cout << "char: '" << static_cast<char>(n) << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    if (n > INT_MAX || n < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(n) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << n << "f\n";
    std::cout << "double: " << static_cast<double>(n) << std::endl;
}

static void printFromDouble(const std::string& str)
{
    double n = std::strtod(str.c_str(), NULL);

    if (n >= 0 && n <= 127)
    {
        if (std::isprint(n))
            std::cout << "char: '" << static_cast<char>(n) << "'\n";
        else
            std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: impossible\n";
    if (n > INT_MAX || n < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(n) << "\n";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(n) << "f\n";
    std::cout << "double: " << n << std::endl;
}

static void printFromPseudo(const std::string &str)
{
    std::cout << "char: impossible\nint: impossible" << std::endl;
    if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
        std::cout << "float: +inff\ndouble: +inf\n";
    else if (str == "-inf" || str == "-inff")
        std::cout << "float: -inff\ndouble: -inf\n";
    else
        std::cout << "float: nanf\ndouble: nan" << std::endl;
}