#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap c;
        ScavTrap d("d");
        ScavTrap e;

        e = d;
        e.attack("c");
        e.takeDamage(19);
        e.takeDamage(2);
        d.beRepaired(7);
        c.attack("e");
        c.beRepaired(2);
        c.guardGate();
        c.guardGate();
    }
    return 0;
}
