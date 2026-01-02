#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "Default Intern Constructor Called" << std::endl;
}

Intern::Intern( Intern& copy )
{
	*this = copy;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern::~Intern( void )
{
	std::cout << "Intern Destructor Called" << std::endl;
}

Intern&	Intern::operator=( const Intern& src )
{
	std::cout << "Intern = Operator Called" << std::endl;
	if (this == &src)
		return *this;
	return *this;
}

static AForm*	createPresidentForm( std::string target )
{
	return (new PresidentialPardonForm( target ));
}

static AForm*	createShrubberyForm( std::string target )
{
	return (new ShrubberyCreationForm( target ));
}

static AForm*	createRobotomyForm( std::string target )
{
	return (new RobotomyRequestForm( target ));
}

AForm*	Intern::makeForm( std::string formName, std::string target )
{
	std::string nameList[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (*fPtrs[]) ( std::string target ) = {&createRobotomyForm, &createPresidentForm, &createShrubberyForm};
	
	for (int i = 0; i < 3; i++)
	{
		if (formName == nameList[i])
		{
			std::cout << "Intern Created " << formName << std::endl;
			return (fPtrs[i]( target ));
		}
	}
	std::cerr << "No Form Called " << formName << std::endl;
	return (NULL);
}