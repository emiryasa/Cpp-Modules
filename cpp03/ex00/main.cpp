#include "ClapTrap.hpp"

int main(void)
{
    {
        ClapTrap a;
        ClapTrap b("b");

        a.attack("b");
        a.takeDamage(10);
        a.takeDamage(5);
        b.beRepaired(3);
        a.beRepaired(5);
    }
    return 0;
}
