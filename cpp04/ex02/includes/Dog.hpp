#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain*	brain;
public:
	Dog		();
	Dog		(const std::string& _type);
	Dog		(const Dog& rhs);
	Dog&	operator=(const Dog& rhs);
	~Dog	();

	void	makeSound()const;
	void	setType(const std::string& _type);
	Brain*	getBrain()const;
};

#endif