#include "../includes/Weapon.hpp"

const std::string	Weapon::getType() const{
	return (this->type);
}

void	Weapon::setType(std::string weaponType){
	this->type = weaponType;
}

Weapon::Weapon(){}

Weapon::~Weapon(){}