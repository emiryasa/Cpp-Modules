#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: Invalid number of arguments\n";
        return 1;
    }

    try {
        RPN calculator(av[1]);
        int result = calculator.calculate();
        std::cout << result << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
