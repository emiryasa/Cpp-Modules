#include "Character.hpp"

Character::Character() : name("default") {}

Character::Character(std::string const &name) : name(name) {}

Character::~Character()
{
    for (size_t i = 0; i <= 3; i++)
    {
        if (this->inventory[i] != nullptr)
            delete this->inventory[i];
    }
}

Character::Character(const Character &copy)
{
    *this = copy;
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        this->name = src.getName();
        for (size_t i = 0; i <= 3; i++)
        {
            if (this->inventory[i] != nullptr)
                delete this->inventory[i];
            if (src.inventory[i])
                this->inventory[i] = src.inventory[i]->clone();
            else 
                this->inventory[i] = nullptr;
        }
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    for (size_t i = 0; i <= 3; i++)
    {
        if (this->inventory[i] == nullptr)
        {
            this->inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if ((idx <= 3 && idx >= 0) && (this->inventory[idx] != nullptr))
    {
        this->inventory[idx] = nullptr;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if ((idx <= 3 && idx >= 0) && (this->inventory[idx] != nullptr))
    {
        this->inventory[idx]->use(target);
    }
}
