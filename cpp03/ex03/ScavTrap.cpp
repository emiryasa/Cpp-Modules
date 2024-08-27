#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
    this->hit_p = 100;
    this->energy_p = 50;
    this->attack_d = 20;
    this->guarding_gate = false;
    std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_p = 100;
    this->energy_p = 50;
    this->attack_d = 20;
    this->guarding_gate = false;
    std::cout << "ScavTrap constructor for the name " << this->name << " called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    std::cout << "ScavTrap assignement operator called" << std::endl;
    if (this != &src)
    {   
        this->energy_p = src.energy_p;
        this->name = src.name;
        this->attack_d = src.attack_d;
        this->hit_p = src.hit_p;
        this->guarding_gate = src.guarding_gate;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_p > 0 && this->energy_p != 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attack_d << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else if (this->energy_p == 0)
        std::cout << "ScavTrap " << this->name << " is not able to attack " << " because he has no energy points left." << std::endl;
    else
        std::cout << "ScavTrap " << this->name << " is not able to attack " << " because he has no hit points left." << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->guarding_gate == false)
    {
        this->guarding_gate = true;
        std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " is already guarding the gate." << std::endl;
}
