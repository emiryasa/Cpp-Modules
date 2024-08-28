#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);
        Ice *Ice::clone() const;
        void use(ICharacter &target);
        ~Ice();
};
