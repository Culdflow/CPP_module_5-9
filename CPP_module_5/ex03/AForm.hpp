#pragma once

#include <fstream>
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <iomanip>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;
		std::string			_target;
	public:
		AForm();
		AForm(const std::string name, const int minGradeToSign, const int minGradeToExecute);
		AForm(AForm& copy);
		virtual ~AForm();

		AForm&	operator=(const AForm& src);

		//getter-------------------------------------
		const std::string	getName( void )const;
		bool				getSigned( void )const;
		int					getMinGradeToSign( void )const;
		int					getMinGradeToExecute( void )const;
		std::string			getTarget( void )const;
		//setter-------------------------------------
		void				setTarget( std::string );
		//member functions---------------------------
		void				beSigned(Bureaucrat &a);
		virtual void		execute(Bureaucrat const & executor)const = 0;

		class FormGradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};

		class FormGradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, AForm *form);