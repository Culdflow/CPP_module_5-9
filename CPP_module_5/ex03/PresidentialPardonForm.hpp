#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm& copy );
		~PresidentialPardonForm( void );

		PresidentialPardonForm& operator=( const PresidentialPardonForm& src );

		void	execute( Bureaucrat const & executor )const;
};