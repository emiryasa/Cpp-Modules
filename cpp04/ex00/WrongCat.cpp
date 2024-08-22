#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = src.type;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
