#include "Harl.hpp"

int main()
{
    Harl harl = Harl();
    std::cout << "DEBUG : ";
    harl.complain("debug");
    std::cout << std::endl
              << "INFO : ";
    harl.complain("info");
    std::cout << std::endl
              << "WARNING : ";
    harl.complain("warning");
    std::cout << std::endl
              << "ERROR : ";
    harl.complain("error");
    
    return 0;
}
