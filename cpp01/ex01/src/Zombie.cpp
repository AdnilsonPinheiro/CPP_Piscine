#include "../includes/Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Creating zombie" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	this->name = name;
}

Zombie::~Zombie(){
	std::cout << "Destroying " << this->name << std::endl;
}