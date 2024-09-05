#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();

        const std::string   getName() const;
        int                 getGrade() const;
        void                incrementGrade();
        void                decrementGrade();

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };   
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);
