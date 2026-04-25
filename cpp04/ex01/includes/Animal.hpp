#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

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

	void				setType(const std::string& _type);
	const std::string&	getType()const;

	virtual void	makeSound()const;
};

#endif