#include "includes/Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name);
static int	stoi(std::string &s);

int	main(){
	std::cout << "How many zombies do you want?" << std::endl;
	std::string hordeNum;
	getline(std::cin, hordeNum);
	int	N = stoi(hordeNum);
	Zombie	*horde = zombieHorde(N, "Mr Popo");
	for (int i = 0; i < N; i++){
		horde[i].announce();
	}
	delete[]horde;
}

static int	stoi(std::string &s){
	int	i;
	std::istringstream(s) >> i;
	return i;
}