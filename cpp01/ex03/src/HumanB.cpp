#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string newName) : name(newName), weapon(NULL) {}

void	HumanB::attack(void)const {
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is unarmed. You wouldn't hit an unarmed person, would you?" << std::endl;
}

void	HumanB::setWeapon(Weapon &newWeapon){
	weapon = &newWeapon;
}

HumanB::~HumanB(void) {}
