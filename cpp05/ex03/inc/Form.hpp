#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form() = delete;
		Form(const std::string name, int signGrade, int execGrade);
		Form(const Form& obj);
		Form&	operator=(const Form& other) = delete;
		virtual ~Form();

		const std::string&  getName() const;
		bool				getSignStatus() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(const Bureaucrat& signer);
		virtual void		execute(const Bureaucrat& executor) const;

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

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
