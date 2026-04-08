#include "./Fixed.hpp"

int	main()
{
	Fixed	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << "a is " << a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a now is " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "a now is " << a << std::endl;

	std::cout << "b is 0.05f * 2, resulting in ";
	std::cout << b << std::endl;

	std::cout << "The greater between a and b is ";
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "The lesser between a and b is ";
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "Is a greater than b? " << (a > b) << std::endl;
	std::cout << "Is a lesser than b? " << (a < b) << std::endl;
	std::cout << "Is a greater than or equal to b? " << (a >= b) << std::endl;
	std::cout << "Is a lesser than or equal to b? " << (a <= b) << std::endl;
	std::cout << "Is a equal to b? " << (a == b) << std::endl;
	std::cout << "Is a different from b? " << (a != b) << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "a-- " << a-- << std::endl;
	std::cout << "a now is " << a << std::endl;
	std::cout << "--a " << --a << std::endl;
	std::cout << "a now is " << a << std::endl;

	std::cout << "2 / 0.5f is " << (Fixed(2) / Fixed(0.5f)) << std::endl;
	std::cout << "2 * 0.5f is " << (Fixed(2) * Fixed(0.5f)) << std::endl;
	std::cout << "2 + 0.5f is " << (Fixed(2) + Fixed(0.5f)) << std::endl;
	std::cout << "2 - 0.5f is " << (Fixed(2) - Fixed(0.5f)) << std::endl;

	return 0;
}