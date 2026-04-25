#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructed a default brain. Could be better" << std::endl;
}

Brain::Brain(const std::string& newIdea)
{
	std::cout << "Constructed a param brain. Got some new ideas" << std::endl;
	for (int i = 0; i < 100; i++){
		this->ideas[i] = newIdea;
	}
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Referenced a brain. Got my ideas from someone" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << "Assigned my brain to somebody else's." << std::endl;
	if (this != &rhs){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destroying my brain..." << std::endl;
}

void	Brain::setIdeas(const std::string& newIdea)
{
	for (int i = 0; i < 100; i++){
		this->ideas[i] = newIdea;
	}
}

const std::string&	Brain::getIdeas(int index)const
{
	return (this->ideas[index]);
}