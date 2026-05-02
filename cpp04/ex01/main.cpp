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
	return 0;
}