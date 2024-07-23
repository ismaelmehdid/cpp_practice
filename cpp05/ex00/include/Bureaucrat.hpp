#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		std::string getName() const;
		int			getGrade() const;
		void		promote();
		void		demote();

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);