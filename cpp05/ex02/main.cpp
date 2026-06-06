#include "inc/Bureaucrat.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	intern("Intern", 150);
	RobotomyRequestForm	robo1;
	RobotomyRequestForm	robo2("Ze das Couves");
	PresidentialPardonForm	pres1;
	PresidentialPardonForm	pres2("Ze dos Paes");
	ShrubberyCreationForm	shr1;
	ShrubberyCreationForm	shr2("Ze dos Bolos");

	std::cout << "\n===== Bureaucrats =====\n" << std::endl;

	std::cout << boss << std::endl;
	std::cout << intern << std::endl;

	std::cout << "\n===== Forms =====\n" << std::endl;

	std::cout << robo1 << std::endl;
	std::cout << robo2 << std::endl;
	std::cout << pres1 << std::endl;
	std::cout << pres2 << std::endl;
	std::cout << shr1 << std::endl;
	std::cout << shr2 << std::endl;

	std::cout << "\n===== Intern tries to execute some of them =====\n" << std::endl;

	try {
		intern.executeForm(robo1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		intern.executeForm(pres1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		intern.executeForm(shr1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Intern tries to sign some of them =====\n" << std::endl;

	try {
		intern.signForm(robo1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		intern.signForm(pres1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		intern.signForm(shr1);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Boss tries to execute some of them, but they're not signed =====\n" << std::endl;

	try {
		boss.executeForm(robo2);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		boss.executeForm(pres2);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try {
		boss.executeForm(shr2);
		std::cout << "This is dead code." << std::endl;
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Boss tries to sign some of them =====\n" << std::endl;

	try {
		boss.signForm(robo2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		boss.signForm(pres2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		boss.signForm(shr2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Boss tries AGAIN to execute some of them =====\n" << std::endl;

	try {
		boss.executeForm(robo2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		boss.executeForm(pres2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}
	try {
		boss.executeForm(shr2);
	}
	catch (std::exception& e){
		std::cout << "This is dead code." << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== A hundred calls to Robotomy =====\n" << std::endl;
	RobotomyRequestForm	rb;
	Bureaucrat			br("Tester bureaucrat", 1);

	br.signForm(rb);
	for (int i = 0; i < 100; i++){
		br.executeForm(rb);
	}

	return 0;
}