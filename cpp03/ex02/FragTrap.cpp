#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default")
{
    this->hit_p = 100;
    this->energy_p = 100;
    this->attack_d = 30;
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_p = 100;
    this->energy_p = 100;
    this->attack_d = 30;
    std::cout << "FragTrap constructor for the name " << this->name << " called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
    *this = src;
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    std::cout << "FragTrap assignement operator called" << std::endl;
    if (this != &src)
    {   
        this->energy_p = src.energy_p;
        this->name = src.name;
        this->attack_d = src.attack_d;
        this->hit_p = src.hit_p;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << ": You want a high five? Here you go." << std::endl; 
}
