#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name")
{
    this->name = "default";
    this->hit_p = 100;
    this->energy_p = 100;
    this->attack_d = 30;
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->name = name;
    this->hit_p = FragTrap::hit_p;
    this->energy_p = ScavTrap::energy_p;
    this->attack_d = FragTrap::attack_d;
    std::cout << "DiamondTrap constructor for the name " << this->name << " called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    std::cout << "DiamondTrap copy constructor called." << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src)
{
    std::cout << "DiamondTrap assignement operator called" << std::endl;
    if (this != &src)
    {
        this->name = src.name;
        this->energy_p = src.energy_p;
        this->attack_d = src.attack_d;
        this->hit_p = src.hit_p;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "Hello i am DiamondTrap named " << this->name << "and i am originated from ClapTrap named" << ClapTrap::name << "." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}
