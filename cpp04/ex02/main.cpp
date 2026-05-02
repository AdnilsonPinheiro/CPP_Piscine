#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int	main()
{
	Cat	cat;
	Animal*	a = &cat;

	/*The cove bellow should not work once uncommented*/

	// Animal	mammal;
	// mammal.setType("generic unexisting abstract animal");
	// mammal.getType();

	a->makeSound();

	Dog	dog;
	dog.setType("doggo");
	std::cout << dog.getType() << std::endl;
	dog.makeSound();
	a->setType("Weird pointy cat");
	std::cout << a->getType() << std::endl;
	return 0;
}