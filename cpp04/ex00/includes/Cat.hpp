#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
public:
	Cat		();
	Cat		(const std::string& _type);
	Cat		(const Cat& rhs);
	Cat&	operator=(const Cat& rhs);
	~Cat	();

	void				setType(const std::string& _type);
	const std::string&	getType()const;

	void	makeSound();
};

#endif