#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : name(""), hit_p(10), energy_p(10), attack_d(0)
{
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_p(10), energy_p(10), attack_d(0)
{
    std::cout << "ClapTrap constructor for the name " << this->name << " called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "ClapTrap copy constructor called." << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
    std::cout << "ClapTrap assignement operator called" << std::endl;
    if (this != &src)
    {   
        this->energy_p = src.energy_p;
        this->name = src.name;
        this->attack_d = src.attack_d;
        this->hit_p = src.hit_p;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_p > 0 && this->energy_p != 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attack_d << " points of damage!" << std::endl;
        this->energy_p--;
    }
    else if (this->energy_p == 0)
        std::cout << "ClapTrap " << this->name << " is not able to attack " << " because he has no energy points left." << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is not able to attack " << " because he has no hit points left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_p > amount)
        this->hit_p -= amount;
    else if (this->hit_p != 0)
        this->hit_p = 0;
    else
    {
        std::cout << "ClapTrap " << this->name << " is already dead." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, his current hit point is " << this->hit_p << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_p != 0 && this->hit_p != 0)
    {
        this->hit_p += amount;
        std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " hit points, his current hit point is " << this->hit_p << "." << std::endl;
        this->energy_p--;
    }
    else if (this->energy_p == 0)
        std::cout << "ClapTrap " << this->name << " could not repaired itself because he has no energy points." << std::endl;
    else if (this->hit_p == 0)
        std::cout << "ClapTrap " << this->name << " could not repaired itself because he has no hit points." << std::endl;
}
