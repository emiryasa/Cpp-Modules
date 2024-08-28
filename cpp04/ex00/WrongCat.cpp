#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
    this->type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat Copy constructor called!" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Meowwww!!" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat default destructor called" << std::endl;
}
