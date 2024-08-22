#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = src.type;
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog deconstructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Hav hav!" << std::endl;
}
