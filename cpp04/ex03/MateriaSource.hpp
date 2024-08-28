#pragma once 
#include "IMateriaSource.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *brain[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &copy);
        MateriaSource &operator=(const MateriaSource &src);
        void learnMateria(AMateria* src);
        AMateria* createMateria(std::string const & type);
        ~MateriaSource();
};
