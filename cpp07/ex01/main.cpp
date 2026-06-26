#include "iter.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "===== [CONST CHAR] =====" << std::endl;

    const char str1[] = {'q', 'w', 'e', 'r', 't', 'y'};

    ::iter(str1, 5, ft_print<char>);
    std::cout << std::endl;

    std::cout << "===== [NON-CONST CHAR] =====" << std::endl;

    char str2[] = {'n', 'o', 'n', '-', 'c', 'o', 'n', 's', 't'};

    ::iter(str2, sizeof(str2), ft_print<char>);
    std::cout << std::endl;

    std::cout << "===== [DEREFERENCING NON-CONST CHAR ARRAY] =====" << std::endl;
    str2[0] = '_';
    ::iter(str2, sizeof(str2), ft_print<char>);
    std::cout << std::endl;
    std::cout << "===== [CONST INT] =====" << std::endl;

    const int array1[] = {0, 1, 2, 3, 4};

    ::iter(array1, sizeof(array1)/sizeof(int), ft_print<int>);
    std::cout << std::endl;

    std::cout << "===== [NON-CONST INT] =====" << std::endl;

    int array2 [] = {9, 8, 7, 6, 5};

    ::iter(array2, sizeof(array2)/sizeof(int), ft_print<int>);
    std::cout << std::endl;

    std::cout << "===== [DEFERENCING NON-CONST INT ARRAY] =====" << std::endl;
    array2[0] = 1;
    ::iter(array2, sizeof(array2)/sizeof(int), ft_print<int>);
    std::cout << std::endl;


    return 0;
}