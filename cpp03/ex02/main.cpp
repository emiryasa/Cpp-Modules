#include "FragTrap.hpp"

int main()
{
    {
        FragTrap c;
        FragTrap d("d");
        FragTrap e;

        e = d;
        e.attack("c");
        e.takeDamage(19);
        e.takeDamage(2);
        d.beRepaired(7);
        c.attack("e");
        c.beRepaired(2);
        c.highFivesGuys();
        d.highFivesGuys();
    }
    return 0;
}

