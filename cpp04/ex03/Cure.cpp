#include "Cure.hpp"


Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &copy)
{
    *this = copy;
}

Cure &Cure::operator=(const Cure &src)
{
    if (this != &src)
    {
        this->type = src.type;
    }
    return *this;
}

Cure *Cure::clone() const
{
    Cure *clone = new Cure(*this);
    if (!clone)
    {
        std::cerr << "Memory allocation error" << std::endl;
        return nullptr;
    }
    return clone;
}

void Cure::use(ICharacter &target)
{
   std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
