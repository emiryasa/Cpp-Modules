#pragma once 

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
    private:
        bool guarding_gate;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &src);
        ScavTrap &operator=(ScavTrap const &src);
        void attack(const std::string& target);
        void guardGate();
        virtual ~ScavTrap();
};
