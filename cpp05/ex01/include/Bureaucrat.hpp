#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class Bureaucrat
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

		Bureaucrat();
		Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		std::string getName() const;
		int			getGrade() const;
		void		promote() throw(GradeTooHighException);
		void		demote() throw(GradeTooLowException);
        void        signForm(Form &form) const;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);