#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = src.type;
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal deconstructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal could make several different sounds" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
