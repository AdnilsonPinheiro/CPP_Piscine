#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
protected:
	std::string	type;
public:
	Animal	();
	Animal	(const std::string& _type);
	Animal	(const Animal& rhs);
	Animal&	operator=(const Animal& rhs);
	virtual ~Animal	();

	virtual void		setType(const std::string& _type) = 0;
	const std::string&	getType()const;

	virtual void	makeSound()const = 0;
};

#endif