#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments\n";
        return 1;
    }

    try {
        RPN calculator(av[1]);
        calculator.calculate();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
