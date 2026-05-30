#include "./inc/Form.hpp"
#include "./inc/Bureaucrat.hpp"

int main()
{
    Bureaucrat  boss("Boss", 2);
    Bureaucrat  intern("Intern", 150);
    Form        highForm("highForm", 3, 3);
    Form        lowForm("lowForm", 150, 150);



    std::cout << "\n===== Form with too low grade =====\n" << std::endl;

    try {
        Form tooLowForm("impossibleForm", 151, 10);
        std::cout << "This is dead code" << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Form with too high grade =====\n" << std::endl;;

    try {
        Form tooHighForm("impossibleForm", 0, 10);
        std::cout << "This is dead code" << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Regular forms =====\n" << std::endl;

    std::cout << highForm << std::endl;
    std::cout << lowForm << std::endl;

    std::cout << "\n===== Boss and Intern =====\n" << std::endl;

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n===== Intern tries to sign forms =====\n" << std::endl;

    try {
        intern.signForm(highForm);
        intern.signForm(lowForm);
        std::cout << "This is dead code" << std::endl;
    }

    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Forms are intact =====\n" << std::endl;

    std::cout << highForm << std::endl;
    std::cout << lowForm << std::endl;

    std::cout << "\n===== Boss tries to sign highForm =====\n" << std::endl;

    try {
        boss.signForm(highForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Forms are signed =====\n" << std::endl;

    std::cout << highForm << std::endl;
    std::cout << lowForm << std::endl;

    return 0;
}