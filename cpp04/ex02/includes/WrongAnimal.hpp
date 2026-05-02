#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal		();
	WrongAnimal		(const std::string& _type);
	WrongAnimal		(const WrongAnimal& rhs);
	WrongAnimal&	operator=(const WrongAnimal& rhs);
	~WrongAnimal	();

	void				setType(const std::string& _type);
	const std::string&	getType()const;

	void	makeSound()const;
};

#endif