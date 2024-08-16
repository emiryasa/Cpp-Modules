#include <iostream>
#include "phonebook.hpp"

Phonebook::~Phonebook()
{
    
}

Phonebook::Phonebook()
{
    
}

void Phonebook::search_contact()
{
    int i = -1;
    while(++i < 8)
        this->contacts[i].get_contact();
}

void Phonebook::add_contact()
{
    static int i = 0;
    if (i == 8)
        i = 0;    
    std::string name;
    std::cout << "Enter a name: ";
    std::getline(std::cin, name);
    this->contacts[i].set_name(name);
    std::string surname;
    std::cout << "Enter a surname: ";
    std::getline(std::cin, surname);
    this->contacts[i].set_surname(surname);
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

void Contact::set_name(std::string name)
{
    this->name = name;
}
