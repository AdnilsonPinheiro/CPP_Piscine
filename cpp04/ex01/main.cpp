#include "includes/Cat.hpp"

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

	const Animal*	j = new Cat();
	delete j;
	std::cout << "ALLOCATED ANIMAL POINTER IS GOOOOONE" << std::endl;
	return 0;
}