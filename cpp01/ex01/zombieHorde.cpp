#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (nullptr);

    Zombie *horde = new Zombie[N];
    if (!horde)
	{
		std::cerr << "Allocate error\n" << std::endl;
		return (nullptr);
	}
    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}