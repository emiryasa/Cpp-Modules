#include "Zombie.hpp"

int main(void)
{
    Zombie *z = newZombie("zombie1");
    z->announce();
    delete z;
    randomChump("zombie2");
}
