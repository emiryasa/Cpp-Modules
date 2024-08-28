#include "AAnimal.hpp"

AAnimal::AAnimal(/* args */)
{
    type = "default";
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    std::cout << "AAnimal Copy constructor called!" << std::endl;
    *this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
    std::cout << "AAnimal Assignation operator called" << std::endl;
    if (this != &src)
        type = src.type;
    return *this;
}

std::string AAnimal::getType() const
{
    std::cout << "AAnimal getType function called" << std::endl;
    return (this->type);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal default destructor called" << std::endl;
}
