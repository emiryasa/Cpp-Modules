#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        AMateria *inventory[4];
        std::string name;

    public:
        Character(/* args */);
        Character(std::string const &name);
        Character(const Character &copy);
        Character &operator=(const Character &src);
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        ~Character();
};
