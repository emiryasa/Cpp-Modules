#pragma once
#include <iostream>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
		Animal(const Animal &);
		Animal& operator=(const Animal &);
		virtual ~Animal();

        std::string     getType() const;
        virtual void    makeSound() const;
};
