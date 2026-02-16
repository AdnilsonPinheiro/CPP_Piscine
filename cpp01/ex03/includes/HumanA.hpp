#ifndef	HUMANA_HPP
#define	HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class	HumanA{
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		void	attack(void)const;

		HumanA(std::string newName, Weapon &newWeapon);
		~HumanA(void);
};

#endif