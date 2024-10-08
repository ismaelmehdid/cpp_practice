#pragma once

#include "Bureaucrat.hpp"

#include <string>

class Form
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Form();
		Form(const std::string &name, const int sign_grade, const int execute_grade) throw(GradeTooHighException, GradeTooLowException);
		Form(const Form &form);
		~Form();
		Form &operator=(const Form &form);

		std::string         getName() const;
        bool                isSigned() const;
        int                 getSigningGrade() const;
        int                 getExecutionGrade() const;
        void                beSigned(const Bureaucrat &bureaucrat) throw(Form::GradeTooLowException);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;	// grade required to sign it
		const int			_execute_grade; // grade required to execute it
};

std::ostream &operator<<(std::ostream &os, const Form &form);