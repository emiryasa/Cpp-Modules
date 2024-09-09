#pragma once

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    private:
        typedef struct s_forms {
            std::string name;
            Form *formClass;
        } t_forms;

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        Form* makeForm(std::string name, std::string target);
};
