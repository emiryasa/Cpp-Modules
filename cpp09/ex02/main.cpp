#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cout << "Error: Invalid number of arguments\n";
        return 1;
    }

    PmergeMe merge;
    merge.getOutput(ac, av);

    return 0;
}
