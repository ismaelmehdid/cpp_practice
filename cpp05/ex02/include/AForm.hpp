#pragma once

#include <string>

class Bureaucrat;
class AForm
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade too high!";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade too low!";
				}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "The form is not signed!";
				}
		};
		AForm();
		AForm(const std::string &name, const int sign_grade, const int execute_grade) throw(GradeTooHighException, GradeTooLowException);
		AForm(const AForm &form);
		virtual ~AForm();
		AForm &operator=(const AForm &form);

		std::string         getName() const;
        bool                isSigned() const;
        int                 getSigningGrade() const;
        int                 getExecutionGrade() const;
        void                beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);
        virtual void        execute(Bureaucrat const & executor) const throw(GradeTooLowException, FormNotSignedException) = 0;

	protected:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;	// grade required to sign it
		const int			_execute_grade; // grade required to execute it
};

std::ostream &operator<<(std::ostream &os, const AForm &form);