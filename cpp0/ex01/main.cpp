#include <iostream>
#include "phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Enter a command > ";
        std::getline(std::cin, str);
        if (str == "ADD")
            phonebook.add_contact();
        else if (str == "SEARCH")
            phonebook.search_contact();
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
    }
    return (0);
}
