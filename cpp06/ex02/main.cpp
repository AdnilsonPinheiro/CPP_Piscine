#include <iostream>
#include "inc/Base.hpp"
#include "inc/A.hpp"
#include "inc/B.hpp"
#include "inc/C.hpp"

int main()
{
    Base *bp = generate();
    identify(bp);
    identify(*bp);
    delete bp;
}