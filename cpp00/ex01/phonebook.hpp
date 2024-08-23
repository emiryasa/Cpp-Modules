#pragma once
#include "Contact.hpp"

class Phonebook{
    private:
        Contact contacts[8];
    public:
        void add_contact();
        void search_contact();
};
