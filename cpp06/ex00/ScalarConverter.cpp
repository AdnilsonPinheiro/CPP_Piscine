#include "ScalarConverter.hpp"

static int isPseudo(const std::string& str)
{
    if (str == "nan" || str == "nanf" || str == "inf" || str == "+inf" || str == "+inff" \
    || str == "-inf" || str == "-inff")
        return true;
    return false;
}


static int inputType(const std::string& str)
{
    if (isPseudo(str))
        return PSEUDO;
    if (str.length() == 1 && !isdigit(str[0]))
        return CHAR;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
            return ERROR;
    }
    size_t p = str.find('.');
    if (p != str.npos)
    {
        p = str.find('.', p + 1);
        if (p != str.npos)
            return ERROR;
        else if (p == str.npos)
        {
            size_t f = str.find('f');
            if (f == str.length() - 1)
                return FLOAT;
            else if (f == str.npos)
                return DOUBLE;
            else
                return ERROR;
        }
    }
    return INT;
}

void ScalarConverter::convert(const std::string& input)
{
    int t = inputType(input);
    std::cout << t << std::endl;
    // switch(t)
    // {
    //     case CHAR:
    //         printFromChar(input);
    //         break;
    //     case INT:
    //         printFromInt(input);
    //         break;
    //     case FLOAT:
    //         printFromFloat(input);
    //         break;
    //     case DOUBLE:
    //         printFromDouble(input);
    //         break;
    //     case PSEUDO:
    //         printFromPseudo(input);
    //         break;
    //     case ERROR:
    //         std::cerr << "Invalid argument. Must represent a C++ literal" << std::endl;
    // }
}