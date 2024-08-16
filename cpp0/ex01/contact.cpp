#include <iostream>
#include "contact.hpp"

Contact::Contact()
{

}
Contact::~Contact()
{

}

void Contact::set_surname(std::string surname)
{
    this->surname = surname;
}

void Contact::set_tel(std::string tel)
{
    this->tel = tel;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

std::string Contact::get_name()
{
    return this->name;
}

std::string Contact::get_surname()
{
    return this->surname;
}

std::string Contact::get_tel()
{
    return this->tel;
}

std::string Contact::get_nickname()
{
    return this->nickname;
}

std::string Contact::get_secret()
{
    return this->secret;
}
