#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->type = src.type;
}

Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Assignment operator overload called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat deconstructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
