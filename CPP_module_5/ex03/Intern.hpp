#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( Intern& copy );
		~Intern( void );

		Intern&	operator=( const Intern& src );

		AForm*	makeForm( std::string formName, std::string target );
};