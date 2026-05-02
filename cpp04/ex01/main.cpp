#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int	main()
{
	Cat	a("kitten");
	Cat	b(a);

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;

	std::cout << a.getBrain() << std::endl;
	std::cout << b.getBrain() << std::endl;

	a.getBrain()->setIdeas("a's ideas");
	b.getBrain()->setIdeas("b's ideas");

	std::cout << a.getBrain()->getIdeas(0) << std::endl;
	std::cout << b.getBrain()->getIdeas(0) << std::endl;

	std::cout << "\n============================\n" << std::endl;

	Dog	x("puppy");
	Dog	y(x);

	std::cout << &x << std::endl;
	std::cout << &y << std::endl;

	std::cout << x.getBrain() << std::endl;
	std::cout << y.getBrain() << std::endl;

	x.getBrain()->setIdeas("x's ideas");
	y.getBrain()->setIdeas("y's ideas");

	std::cout << x.getBrain()->getIdeas(99) << std::endl;
	std::cout << y.getBrain()->getIdeas(99) << std::endl;
	std::cout << x.getBrain()->getIdeas(99) << std::endl;

	std::cout << "\n============================\n" << std::endl;

	const Animal*	j = new Cat();
	delete j;
	std::cout << "ALLOCATED ANIMAL POINTER IS GOOOOONE" << std::endl;

	std::cout << "\n============================\n" << std::endl;

	int	size = 4;
	Animal const*	animal[size];

	for (int i = 0; i < size; i++){
		if (i < size / 2){
			animal[i] = new Dog();
		}
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < size; i++){
		animal[i]->makeSound();
	}

	for (int i = 0; i < size; i++){
		delete(animal[i]);
	}
	return 0;
}