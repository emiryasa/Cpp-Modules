#pragma once
#include <iostream>
#include <string>

class ClapTrap {
    private:
        std::string name;
        int hit_p;
        int energy_p;
        int attac_p;
    public:
        ClapTrap(std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ~ClapTrap();
};
