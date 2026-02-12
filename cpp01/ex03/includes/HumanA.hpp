#ifndef	HUMANA_HPP
#define	HUMANA_HPP

#include "../includes/Weapon.hpp"

class	HumanA{
	private:
		Weapon		Weapon;
		std::string	name;
	public:
		void	attack()const;

		HumanA(std::string name, Weapon::Weapon.getType());
		~HumanA();
};

#endif