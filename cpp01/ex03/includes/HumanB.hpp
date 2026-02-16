#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		void	attack(void)const;
		void	setWeapon(Weapon &newWeapon);

		HumanB(std::string newName);
		~HumanB(void);
};

#endif