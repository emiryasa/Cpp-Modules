#include <iostream>
#include "phonebook.hpp"

Phonebook::~Phonebook()
{
    
}

Phonebook::Phonebook()
{
    
}

void    Contact::print_with_details()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Tel: " << tel << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Secret: " << secret << std::endl;
}

std::string pass_space(std::string str)
{
    size_t len = str.length();
    if (len > 10)
    {
        str.resize(9);
        return(str + ".");
    }
    else
    {
        while (len++ < 10)
            str = " " + str;
        return (str);
    }
}

void Contact::print_user()
{
    static int i = 0;
    if (i == 8)
        i = 0;
    std::cout << "|" << pass_space(std::to_string(i));
    std::cout << "|" << pass_space(name);
    std::cout << "|" << pass_space(surname);
    std::cout << "|" << pass_space(nickname) << "|" << std::endl;
    i++;
}

void Phonebook::search_contact()
{
    std::cout << "|     index|first name| last name|  nickname|" << std::endl;
    for (int j = 0; j < 8; ++j)
        contacts[j].print_user();

    bool validIndex = false;
    int i;
    while (!validIndex)
    {
        std::cout << "Enter an index between 0 and 7: ";
        std::cin >> i;

        if (std::cin.eof())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            return;
        }
        else if (std::cin.fail() || i < 0 || i > 7)
        {
            std::cout << "Invalid index. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            validIndex = true;
    }

    contacts[i].print_with_details();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Phonebook::add_contact()
{
    static int i = 0;
    if (i == 8)
        i = 0;    
    std::string name;
    std::cout << "Enter a name: ";
    std::getline(std::cin, name);
    if (std::cin.eof())
        std::exit(0);
    this->contacts[i].set_name(name);
    std::cout << "Enter a surname: ";
    std::getline(std::cin, name);
    this->contacts[i].set_surname(name);
    std::string tel;
    std::cout << "Enter a tel: ";
    std::getline(std::cin, tel);
    this->contacts[i].set_tel(tel);
    std::string nickname;
    std::cout << "Enter a nickname: ";
    std::getline(std::cin, nickname);
    this->contacts[i].set_nickname(nickname);
    std::string secret;
    std::cout << "Enter a secret: ";
    std::getline(std::cin, secret);
    this->contacts[i].set_secret(secret);
    i++;
}
