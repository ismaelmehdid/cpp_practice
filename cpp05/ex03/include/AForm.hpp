#pragma once

#include "Bureaucrat.hpp"

#include <string>

class AForm
{
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
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
        void                beSigned(const Bureaucrat &bureaucrat) throw(Bureaucrat::GradeTooLowException);
        void                execute(Bureaucrat const & executor) const throw(Bureaucrat::GradeTooLowException, FormNotSignedException);

    protected:
        virtual void        executeForm(void) const = 0;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;	// grade required to sign it
		const int			_execute_grade; // grade required to execute it
};

std::ostream &operator<<(std::ostream &os, const AForm &form);