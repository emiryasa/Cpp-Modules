#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(std::string name, std::string target)
{
    static const t_forms forms[] = {
        {"robotomy request", new RobotomyRequestForm(target)},
        {"presidential pardon", new PresidentialPardonForm(target)},
        {"shrubbery creation", new ShrubberyCreationForm(target)}
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i].name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return forms[i].formClass;
        }
    }

    std::cout << "Intern cannot create " << name << std::endl;
    return NULL;
}
