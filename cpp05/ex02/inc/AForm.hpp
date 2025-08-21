#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "../inc/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm() = delete;
		AForm(const std::string name, int signGrade, int execGrade);
		AForm(const AForm& obj);
		AForm&	operator=(const AForm& other) = delete;
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat& who);
		virtual void		execute(const Bureaucrat& executor) const = 0;

		class NotSignedException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};

		class AlreadySignedException : public std::exception
		{
			public:
				const char*	what() const noexcept override;
		};

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

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif
