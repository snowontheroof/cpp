#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _execGrade;

    public:
        Form() = delete;
        Form(const std::string name, int signGrade, int execGrade);
        Form(const Form& obj);
        Form&   operator=(const Form& other) = delete;
        ~Form();

        const std::string&  getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        void                GradeTooHighException() const;
        void                GradeTooLowException() const; 
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif