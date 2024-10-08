#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
    this->name = name;
}

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}

HumanA::~HumanA()
{
}
