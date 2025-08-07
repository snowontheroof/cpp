#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& obj);
        const Bureaucrat&   operator=(const Bureaucrat& other) = delete;
        ~Bureaucrat();

        const std::string&  getName() const;
        int                 getGrade() const;
        void                upGrade();
        void                downGrade();
        void                GradeTooHighException() const;
        void                GradeTooLowException() const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif