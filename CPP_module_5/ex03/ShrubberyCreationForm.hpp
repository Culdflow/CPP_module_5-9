#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm& copy );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& src );

		void	execute(Bureaucrat const & executor)const;
};