#include "contact.hpp"

class Phonebook{
    private:
        Contact contacts[8];
    public:
        Phonebook();
        void add_contact();
        void search_contact();
        ~Phonebook();
};
