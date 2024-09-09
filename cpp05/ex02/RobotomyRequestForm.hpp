#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public Form
{
    private:
        const std::string _target;
    public:

        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        virtual ~RobotomyRequestForm();

        std::string getTarget() const;
        void execute(const Bureaucrat &executor) const;
};
