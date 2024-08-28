#include "Ice.hpp"


Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &copy)
{
    *this = copy;
}

Ice &Ice::operator=(const Ice &src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

Ice *Ice::clone() const
{
    Ice *clone = new Ice(*this);
    return clone;
}

void Ice::use(ICharacter &target)
{
   std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
