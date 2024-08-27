#pragma once 

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
        DiamondTrap &operator=(DiamondTrap const &src);
        void attack(const std::string& target);
        void whoAmI();
        ~DiamondTrap();
};
