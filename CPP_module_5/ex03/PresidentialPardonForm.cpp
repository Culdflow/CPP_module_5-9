#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "Default PresidentialPardonForm Constructor Called" << std::endl;
	this->setTarget("Random Target");
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructor Called" << std::endl;
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm& copy ): AForm(copy)
{
	std::cout << "Copy PresidentialPardonForm Constructor Called" << std::endl;
	this->setTarget(copy.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src )
{
	this->setTarget(src.getTarget());
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const & executor )const
{
	if (executor.get_grade() <= this->getMinGradeToExecute())
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw Bureaucrat::GradeTooLowException();
}