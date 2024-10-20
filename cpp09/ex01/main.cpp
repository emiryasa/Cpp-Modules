#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Error: Invalid number of arguments\n";
        return 1;
    }

    try {
        RPN calculator(av[1]);
        calculator.calculate();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
