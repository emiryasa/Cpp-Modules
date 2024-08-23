#include "Phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Enter a command ADD, SEARCH or EXIT: ";
        std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            return (0);
        }
        if (str == "ADD")
            phonebook.add_contact();
        else if (str == "SEARCH")
            phonebook.search_contact();
        else if (str == "EXIT")
            return (0);
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}
