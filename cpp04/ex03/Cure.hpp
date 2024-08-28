#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
    private:

    public:
        Cure();
        Cure(const Cure &copy);
        Cure &operator=(const Cure &src);
        Cure *clone() const;
        void use(ICharacter &target);
        ~Cure();
};
