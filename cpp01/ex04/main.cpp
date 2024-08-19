#include "Sed.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return std::cout << "Usage: ./sed <filename> s1 s2" << std::endl, 0;
    Sed file(av[1], av[2], av[3]);
    if (file.replace())
        return 1;
    return 0;
}
