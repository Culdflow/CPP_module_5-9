#pragma once

#include <fstream>
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <iomanip>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
	public:
		Form();
		Form(const std::string name, const int minGradeToSign, const int minGradeToExecute);
		Form(Form& copy);
		~Form();

		Form&	operator=(const Form& src);

		//getter-------------------------------------
		const std::string	getName( void )const;
		bool				getSigned( void )const;
		int					getMinGradeToSign( void )const;
		int					getMinGradeToExecute( void )const;
		//member functions---------------------------
		void				beSigned(Bureaucrat &a);

		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, Form *form);