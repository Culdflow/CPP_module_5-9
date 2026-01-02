#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "Default RobotomyRequestForm Construcor Called" << std::endl;
	this->setTarget("Random target");
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor Called" << std::endl;
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm& copy ): AForm(copy)
{
	std::cout << "copy RobotomyRequestForm Constructor Called" << std::endl;
	this->setTarget(copy.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& src )
{
	this->setTarget(src.getTarget());
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor )const
{
	if (executor.get_grade() <= this->getMinGradeToExecute())
	{
		std::srand(std::time(NULL));
		int	rand = std::rand();
		std::cout << "DRRRRRRR ZRRRRRRR ZRZR ZR ZRRRRR.." << std::endl;
		if (rand % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << " failed to be robotomized" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}