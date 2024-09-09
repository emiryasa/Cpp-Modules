#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
    private:
        const std::string _target;
    public:

        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        virtual ~ShrubberyCreationForm();

        std::string getTarget() const;
        void		execute(const Bureaucrat& executor) const;
};
