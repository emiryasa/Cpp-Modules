#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return std::cout << "argument number must be two" << std::endl, 0;
    
    Harl harl;
    harl.complain(av[1]);
    
    return 0;
}
