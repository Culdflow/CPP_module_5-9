#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm& copy );
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=( const RobotomyRequestForm& src );

		void	execute( Bureaucrat const & executor )const;
};