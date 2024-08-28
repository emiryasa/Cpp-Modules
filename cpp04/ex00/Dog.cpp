#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy constructor called!" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog default destructor called" << std::endl;
}
