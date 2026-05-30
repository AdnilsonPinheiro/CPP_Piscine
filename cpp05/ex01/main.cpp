#include "./inc/AForm.hpp"
#include "./inc/Bureaucrat.hpp"

int main()
{
    Bureaucrat  boss("Boss", 2);
    Bureaucrat  intern("Intern", 150);
    AForm        highAForm("highAForm", 3, 3);
    AForm        lowAForm("lowAForm", 150, 150);



    std::cout << "\n===== AForm with too low grade =====\n" << std::endl;

    try {
        AForm tooLowAForm("impossibleAForm", 151, 10);
        std::cout << "This is dead code" << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== AForm with too high grade =====\n" << std::endl;;

    try {
        AForm tooHighAForm("impossibleAForm", 0, 10);
        std::cout << "This is dead code" << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Regular AForms =====\n" << std::endl;

    std::cout << highAForm << std::endl;
    std::cout << lowAForm << std::endl;

    std::cout << "\n===== Boss and Intern =====\n" << std::endl;

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n===== Intern tries to sign AForms =====\n" << std::endl;

    try {
        intern.signAForm(highAForm);
        intern.signAForm(lowAForm);
        std::cout << "This is dead code" << std::endl;
    }

    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== AForms are intact =====\n" << std::endl;

    std::cout << highAForm << std::endl;
    std::cout << lowAForm << std::endl;

    std::cout << "\n===== Boss tries to sign highAForm =====\n" << std::endl;

    try {
        boss.signAForm(highAForm);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== AForms are signed =====\n" << std::endl;

    std::cout << highAForm << std::endl;
    std::cout << lowAForm << std::endl;

    return 0;
}