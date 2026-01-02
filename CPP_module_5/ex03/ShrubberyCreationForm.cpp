#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
	this->setTarget("Random Target");
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm& copy ): AForm(copy)
{
	std::cout << "Copy ShrubberyCreationForm Constructor Called" << std::endl;
	this->setTarget(copy.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src )
{
	this->setTarget(src.getTarget());
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor )const
{
	if (executor.get_grade() <= this->getMinGradeToExecute())
	{
		std::ofstream file;
		std::string _shrub = "_shrubbery";
		file.open((this->getTarget() + _shrub).c_str());
		file << "\n       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\nejm97  }|{";
		file.close();
	}
	else
		throw Bureaucrat::GradeTooLowException();
}