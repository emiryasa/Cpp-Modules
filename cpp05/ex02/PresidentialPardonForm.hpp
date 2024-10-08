#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public Form
{
    private:
        const std::string _target;
    public:

        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        virtual ~PresidentialPardonForm();

        std::string getTarget() const;
        void        execute(const Bureaucrat &executor) const;
};
