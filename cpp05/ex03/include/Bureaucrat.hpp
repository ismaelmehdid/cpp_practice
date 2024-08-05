#pragma once

#include <string>
#include <iostream>

class AForm;
class Bureaucrat
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

		Bureaucrat();
		Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		std::string getName() const;
		int			getGrade() const;
		void		promote() throw(GradeTooHighException);
		void		demote() throw(GradeTooLowException);
        void        signForm(AForm &form) const;
        void        executeForm(AForm const & form);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);