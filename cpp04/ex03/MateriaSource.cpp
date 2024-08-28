#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (size_t i = 0; i <= 3; i++)
        {
            if (this->brain[i] != nullptr)
                delete this->brain[i];
            this->brain[i] = src.brain[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria*src)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->brain[i] == nullptr)
        {
            this->brain[i] = src;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (this->brain[i]->getType() == type)
            return this->brain[i]->clone();
    }
    return 0;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i <= 3; i++)
    {
        if (this->brain[i] != nullptr)
            delete this->brain[i];
    }
}
