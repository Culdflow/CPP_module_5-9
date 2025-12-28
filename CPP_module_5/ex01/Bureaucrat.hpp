#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "Form.hpp"
#include <bits/stdc++.h> 
#include <iomanip>

class Form;

class Bureaucrat
{
	private:
		std::string		_name;
		int				_grade;
	public:
		Bureaucrat();
		Bureaucrat( int grade, std::string name );
		Bureaucrat( Bureaucrat& copy );
		~Bureaucrat();

		Bureaucrat&	operator=( const Bureaucrat& src );

		std::string	get_name()const;
		int			get_grade()const;

		void		set_grade( int grade );

		void		incr_grade();
		void		decr_grade();
		void		signForm( Form& form );
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

std::ostream	&operator<<( std::ostream &o, Bureaucrat *src );