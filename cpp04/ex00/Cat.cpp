#include "Cat.hpp"

Cat::Cat(void)
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy constructor called!" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        type = src.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meowwww!!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat default destructor called" << std::endl;
}
