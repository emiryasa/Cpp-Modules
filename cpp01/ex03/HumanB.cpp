#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(const Weapon &weapon)
{
    this->weapon = (Weapon *)&weapon;
}

HumanB::~HumanB()
{
}