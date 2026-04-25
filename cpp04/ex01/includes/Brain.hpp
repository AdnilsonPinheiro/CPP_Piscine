#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
protected:
	std::string	ideas[100];
public:
	Brain	();
	Brain	(const std::string& newIdea);
	Brain	(const Brain& rhs);
	Brain&	operator=(const Brain& rhs);
	~Brain	();

	void				setIdeas(const std::string& newIdea);
	const std::string&	getIdeas(int index)const;
};

#endif