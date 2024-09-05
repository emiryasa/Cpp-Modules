#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    public:
        Form();
        Form(Form const& src);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form &operator=(Form const& src);
        ~Form();

        const std::string   &getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void                beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &src);
