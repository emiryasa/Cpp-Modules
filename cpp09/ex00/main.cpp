#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return std::cerr << "Error: could not open file." << std::endl, 1;

    try {
        BitcoinExchange b(av[1]);

        b.getBitcoinExchange();
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
