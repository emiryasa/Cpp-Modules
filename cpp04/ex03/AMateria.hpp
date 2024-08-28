#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:

    public:
        AMateria();
        AMateria(const AMateria &src);
        AMateria &operator=(const AMateria &src);
        ~AMateria();
        AMateria(std::string const &type);
        std::string const &getType() const;
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};
