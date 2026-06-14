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
    int f_count = 0;
    int d_count = 0;

    if (isPseudo(str))
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

void ScalarConverter::convert(const std::string& input)
{
    int t = inputType(input);
    switch(t)
    {
        case CHAR:
            printFromChar(input);
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