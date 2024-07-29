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

		AForm();
		AForm(const std::string &target);
		AForm(const AForm &form);
		AForm &operator=(const AForm &form);
		virtual ~AForm() = 0;

		std::string         getName() const;
        bool                isSigned() const;
        int                 getSigningGrade() const;
        int                 getExecutionGrade() const;
        void                beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;	// grade required to sign it
		const int			_execute_grade; // grade required to execute it
};
