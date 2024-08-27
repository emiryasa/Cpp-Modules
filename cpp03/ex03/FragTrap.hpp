#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
    private:

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        FragTrap &operator=(FragTrap const &src);
        void highFivesGuys(void);
        virtual ~FragTrap();
};
