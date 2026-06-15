#include "../inc/Base.cpp"

~Base::Base(){}

Base* generate (void)
{
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    int i = std::rand() % 3;
    if (i == 0)
        Base* base = new A();
    else if (i == 1)
        Base* base = new B();
    else
        Base* base = new C();
    return base;
}

void identify(Base* p)
{
    if (!p)
        std::cerr << "Function IDENTIFY called with null pointer" << std::endl; 
    if (std::dynamic_cast<A>(p) != NULL)
        std::cout << "Object identified through pointer: Class A" << std::endl;
    else if (std::dynamic_cast<B>(p) != NULL)
        std::cout << "Object identified through pointer: Class B" << std::endl;
    else if (std::dynamic_cast<C>(p) != NULL)
        std::cout << "Object identified through pointer: Class C" << std::endl;
    else
        std::cout << "This object is of unidentified class" << std::endl;
}
void identify(Base& p)
{
    try {
        A& objRef = dynamic_cast<A&>(p);
        std::cout << "Object identified by reference: class A" << std::cout;
    }
    catch (const std::bad_cast& e)
        (void);
    try {
        B& objRef = dynamic_cast<B&>(p);
        std::cout << "Object identified by reference: class B" << std::cout;
    }
    catch (const std::bad_cast& e)
        (void);
    try {
        C& objRef = dynamic_cast<C&>(p);
        std::cout << "Object identified by reference: class C" << std::cout;
    }
    catch (const std::bad_cast& e)
        (void);
}