#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>
#include <iostream>

int main()
{
    std::cout << "[LIST TEST]" << std::endl;

    std::list<int>  lst;
    int             v1 = 1;
    int             v2 = 7;

    lst.push_back(2);
    lst.push_back(5);
    lst.push_back(1);
    lst.push_back(4);
    lst.push_back(9);

    try
    {
        std::list<int>::const_iterator it1 = easyfind(lst, v1);
        std::cout << "Value found: " << *it1 << std::endl;
        std::list<int>::const_iterator it2 = easyfind(lst, v2);
        std::cout << "Value found: " << *it2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "[VECTOR TEST]" << std::endl;

    std::vector<int>    vect;
    int                 v3 = 10;
    int                 v4 = 70;

    vect.push_back(20);
    vect.push_back(10);
    vect.push_back(40);
    vect.push_back(10);

    try
    {
        std::vector<int>::const_iterator it3 = easyfind(vect, v3);
        std::cout << "Value found: " << *it3 << std::endl;
        std::vector<int>::const_iterator it4 = easyfind(vect, v4);
        std::cout << "Value found: " << *it4 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "[DEQUE TEST]" << std::endl;

    std::deque<int> deq;
    int             v5 = 100;
    int             v6 = 700;

    deq.push_back(200);
    deq.push_back(100);
    deq.push_back(500);
    deq.push_back(199);

    try
    {
        std::deque<int>::const_iterator it5 = easyfind(deq, v5);
        std::cout << "Value found: " << *it5 << std::endl;
        std::deque<int>::const_iterator it6 = easyfind(deq, v6);
        std::cout << "Value found: " << *it6 << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}