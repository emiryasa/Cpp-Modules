#include "Dog.hpp"

Dog::Dog(void)
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain(); 
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy constructor called!" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog Assignation operator called" << std::endl;
    if (this != &src)
    {
        type = src.type;
        brain = new Brain(*src.brain);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!!" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog default destructor called" << std::endl;
    delete this->brain;
}

void Dog::setBrainIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return brain->getIdea(index);
}
