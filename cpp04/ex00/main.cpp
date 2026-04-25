#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int	main()
{
	Animal*	meta = new Animal();
	Cat*	kitty = new Cat();
	Dog*	puppy = new Dog();

	std::cout << kitty->getType() << std::endl;
	std::cout << puppy->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	kitty->makeSound();
	puppy->makeSound();
	meta->makeSound();

	delete meta;
	delete kitty;
	delete puppy;

	std::cout << "\n=====================\n" << std::endl;

	Animal	generic_animal;
	Animal	mammal("mammal");
	Cat		kit;
	Cat		kitten = kit;
	Dog		doggo;
	Dog		good_boy;

	good_boy = doggo;

	mammal.setType("noType");
	std::cout << mammal.getType() << std::endl;
	std::cout << generic_animal.getType() << std::endl;
	generic_animal.makeSound();

	kitten.setType("smol");
	std::cout << kitten.getType() << std::endl;
	kitten.makeSound();

	good_boy.setType("goodest boy");
	std::cout << good_boy.getType() << std::endl;
	good_boy.makeSound();

	std::cout << "\n=====================\n" << std::endl;

	WrongAnimal*	w = new WrongCat();
	w->makeSound();
	delete w;
	return 0;
}