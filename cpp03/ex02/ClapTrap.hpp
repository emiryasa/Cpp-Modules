#pragma once

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string name;
        unsigned int hit_p;
        unsigned int energy_p;
        unsigned int attack_d;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &src);
        ClapTrap &operator=(ClapTrap const &src);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        virtual ~ClapTrap();
};
