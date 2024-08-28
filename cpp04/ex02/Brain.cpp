#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain Copy constructor called!" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain Assignation operator called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = src.ideas[i];
    }
    return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "index error";
}

Brain::~Brain()
{
    std::cout << "Brain default destructor called" << std::endl;
}
