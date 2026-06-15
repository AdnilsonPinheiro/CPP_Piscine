#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base::~Base(){}

Base* generate (void)
{
    std::cout << "[Generating type]: ";
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(time(NULL));
        seeded = true;
    }
    int i = std::rand() % 3;
    switch(i)
    {
        case 0:
            std::cout << "A" << std::endl;
            return (new A());
        case 1:
            std::cout << "B" << std::endl;
            return (new B());
        case 2:
            std::cout << "C" << std::endl;
            return (new C());
    }
    return NULL;
}

void identify(Base* p)
{
    if (!p)
        std::cerr << "Function IDENTIFY called with null pointer" << std::endl; 
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Object identified through pointer: Class A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Object identified through pointer: Class B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Object identified through pointer: Class C" << std::endl;
    else
        std::cout << "This object is of unidentified class" << std::endl;
}
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Object identified by reference: class A" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Object identified by reference: class B" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Object identified by reference: class C" << std::endl;
        return;
    }
    catch (std::bad_cast &e){}
}