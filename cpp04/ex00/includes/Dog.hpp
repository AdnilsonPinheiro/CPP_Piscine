#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
public:
	Dog		();
	Dog		(const std::string& _type);
	Dog		(const Dog& rhs);
	Dog&	operator=(const Dog& rhs);
	~Dog	();

	void	makeSound()const;
};

#endif