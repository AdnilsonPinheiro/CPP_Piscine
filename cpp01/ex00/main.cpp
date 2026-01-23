#include "includes/Zombie.hpp"

int	main(){
	Zombie	*freshNewZombie = newZombie("freshNewZombie");
	randomChump("randomChump");
	freshNewZombie->announce();
	delete freshNewZombie;
}