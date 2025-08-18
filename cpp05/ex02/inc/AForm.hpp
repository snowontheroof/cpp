#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
    protected:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    public:
        AForm() = delete;
        AForm(const std::string name, int signGrade, int execGrade);
        AForm(const AForm& obj);
        AForm&   operator=(const AForm& other) = delete;
        virtual ~AForm();

        virtual const std::string&  getName() const = 0;
        virtual int                 getSignGrade() const = 0;
        virtual int                 getExecGrade() const = 0;
        virtual void                beSigned(const Bureaucrat& who) = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif