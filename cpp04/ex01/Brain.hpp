#pragma once

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &src);
        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;
        ~Brain();
};
