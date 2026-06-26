#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "\n===== NUMBERS ARRAY =====\n" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    std::cout << "\n===== MIRROR ARRAY =====\n" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << mirror[i] << " ";
    std::cout << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "\n ===== TMP ARRAY = NUMBERS =====\n" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
            std::cout << tmp[i] << " ";
        std::cout << std::endl;

        for (int i = 0; i < MAX_VAL; i++){
            if (tmp[i] != numbers[i]){
                std::cerr << "tmp and numbers are different!!" << std::endl;
                return 1;
            }
        }
        std::cout << "\n ===== NUMBER AND TMP ARE IDENTICAL =====\n" << std::endl;
        if (&tmp == &numbers)
        {
            std::cerr << "tmp and numbers have the same address!!" << std::endl;
            return 2;
        }
        else
            std::cout << "tmp and numbers have different memory addresses" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 3;
        }
    }
    std::cout << "\n ===== NUMBER AND MIRROR ARE IDENTICAL =====\n" << std::endl;

    std::cout << "\n ===== TRY TO ACCESS INDEXES OUT OF BOUNDARIES =====\n" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    std::cout << "\n===== NEW NUMBERS ARRAY =====\n" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
        std::cout << numbers[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "\n===== NEW NUMBERS IS DIFFERENT FROM MIRROR =====\n" << std::endl;
            break;
        }
    }

    delete [] mirror;//
    return 0;
}