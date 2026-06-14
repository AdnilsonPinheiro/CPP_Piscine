#include "ScalarConverter.hpp"

static int inputType(const std::string& str);
static void printFromChar(const char c);
static void printFromPseudo(const std::string &str);

void ScalarConverter::convert(const std::string& input)
{
    int t = inputType(input);
    switch(t)
    {
        case CHAR:
            printFromChar(input[0]);
            break;
        // case INT:
        //     printFromInt(input);
        //     break;
        // case FLOAT:
        //     printFromFloat(input);
        //     break;
        // case DOUBLE:
        //     printFromDouble(input);
        //     break;
        case PSEUDO:
            printFromPseudo(input);
            break;
        case ERROR:
            std::cerr << "Invalid argument. Must represent a C++ literal" << std::endl;
    }
}

static int inputType(const std::string& str)
{
    int f_count = 0;
    int d_count = 0;

    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || \
        str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return PSEUDO;
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '-'){
            if (i != 0)
                return ERROR;
        }
        else if (str[i] == '.'){
            if (!isdigit(str[i + 1]))
                return ERROR;
            d_count++;
        }
        else if (str[i] == 'f'){
            if (i != (str.length() - 1))
                return ERROR;
            f_count++;
        }
        else if (!isdigit(str[i]) && str[i] != '-' && str[i] != '.' && str[i] != 'f')
            return ERROR;
    }
    if (d_count > 1)
        return ERROR;
    if (f_count)
        return FLOAT;
    if (d_count)
        return DOUBLE;
    return INT;
}

static void printFromChar(const char c)
{
    if (std::isprint(c))
        std::cout << "char: '" << c << "'\n";
    else
        std::cout << "char: Non displayable\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << std::fixed <<std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f\n";
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void printFromPseudo(const std::string &str)
{
    std::cout << "char: impossible\nint: impossible" << std::endl;
    if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
        std::cout << "float: +inff\ndouble: +inf" << std::endl;
    else if (str == "-inf" || str == "-inff")
        std::cout << "float: -inff\ndouble: -inf" << std::endl;
    else
        std::cout << "float: nanf\ndouble: nan" << std::endl;
}