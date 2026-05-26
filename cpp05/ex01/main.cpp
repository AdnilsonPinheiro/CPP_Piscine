#include "./inc/Form.hpp"
#include "./inc/Bureaucrat.hpp"

int main()
{
    Bureaucrat A("Biro", 150);
    Form F;

    try{
        A.signForm(F);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Excepetion: " << e.what() << std::endl;
    }
}