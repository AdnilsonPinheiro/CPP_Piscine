#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string str1 = "abc";
    std::string str2 = "xyz";

    int a = 1;
    int b = 2;

    std::cout << "===== Current Variables =====" << std::endl;

    std::cout << "str1: " << str1 << "\n" << "str2: " << str2 << std::endl;
    std::cout << "int a: " << a << "\n" << "int b: " << b << std::endl;

    std::cout << "===== Swapped Variables =====" << std::endl;

    ::swap(str1, str2);
    ::swap(a, b);

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "int a: " << a << std::endl;
    std::cout << "int b: " << b << std::endl;

    std::cout << "===== Greater and Lesser =====" << std::endl;

    std::cout << "Greater between int a and int b: " << ::max(a, b) << std::endl;
    std::cout << "Lesser between int a and int b: " << ::min(a, b) << std::endl;

    std::cout << "Greater between str1 and str2: " << ::max(str1, str2) << std::endl;
    std::cout << "Lesser between str1 and str2: " << ::min(str1, str2) << std::endl;

    return 0;

}