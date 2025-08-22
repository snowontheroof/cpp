#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat() = delete;
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat&	operator=(const Bureaucrat& other) = delete;
		~Bureaucrat();

		const std::string&	getName() const;
		int					getGrade() const;
		void				upGrade();
		void				downGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
