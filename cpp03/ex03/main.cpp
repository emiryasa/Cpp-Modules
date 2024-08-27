#include "DiamondTrap.hpp"

int main()
{
    {
        DiamondTrap a;
        DiamondTrap b("b");
        DiamondTrap c(a);
        a.whoAmI();
        a.attack("some guys");
        b.whoAmI();
        b.attack("robots");
        c.whoAmI();
    }
    return 0;
}
