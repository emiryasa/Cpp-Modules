#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:

    public:
        Ice();
        Ice(const Ice &copy);
        Ice &operator=(const Ice &src);
        Ice *clone() const;
        void use(ICharacter &target);
        ~Ice();
};
