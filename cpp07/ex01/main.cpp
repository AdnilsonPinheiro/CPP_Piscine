#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "===== [CONST CHAR] =====" << std::endl;

    const char str1[] = {'q', 'w', 'e', 'r', 't', 'y'};

    ::iter(str1, 5, ft_print<char>);
    std::cout << std::endl;

    return 0;
}