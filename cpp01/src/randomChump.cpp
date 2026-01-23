#include "../includes/zombie.hpp"

void	randomChump(std::string name){
	Zombie	randomChump(name);
	randomChump.announce();
}