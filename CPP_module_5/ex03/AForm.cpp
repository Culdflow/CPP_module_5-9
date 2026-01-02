#include "AForm.hpp"

AForm::AForm(): _name("Default Form"), _signed(false), _minGradeToSign(150), _minGradeToExecute(150), _target("No Target")
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

AForm::AForm(const std::string name, const int minGradeToSign, const int minGradeToExecute): _name(name), _signed(false), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute), _target("No Target")
{
	std::cout << "Form Constructor Called" << std::endl;
	const int signGrade = this->getMinGradeToSign();
	const int executeGrade = this->getMinGradeToExecute();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::FormGradeTooLowException();
	else if( signGrade < 1 || executeGrade < 1)
		throw AForm::FormGradeTooHighException();
}

AForm::AForm(AForm& copy): _name(copy.getName()), _signed(false), _minGradeToSign(copy.getMinGradeToSign()), _minGradeToExecute(copy.getMinGradeToExecute()), _target("No Target")
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form Destructor Called" << std::endl;
}

AForm&	AForm::operator=(const AForm& src)
{
	std::cout << "Form Assignation Operator Called" << std::endl;
	(void)src;
	return (*this);
}

const std::string	AForm::getName( void )const
{
	return (this->_name);
}

bool	AForm::getSigned( void )const
{
	return (this->_signed);
}

int	AForm::getMinGradeToExecute( void )const
{
	return (this->_minGradeToExecute);
}

int	AForm::getMinGradeToSign( void )const
{
	return (this->_minGradeToSign);
}

std::string	AForm::getTarget( void )const
{
	return (this->_target);
}

void	AForm::setTarget( std::string target )
{
	this->_target = target;
}

void	AForm::beSigned(Bureaucrat &signer)
{
	if ((int)signer.get_grade() > this->getMinGradeToSign())
	{
		std::cerr << signer.get_name() << " couldn’t sign " << this->getName() << " because his grade is too low" << std::endl;
		throw(Bureaucrat::GradeTooLowException());
	}
	else if (this->getSigned() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.get_name() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const char*	AForm::FormGradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high");
};

const char*	AForm::FormGradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low");
};

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getMinGradeToSign() <<
	"\n\texec-grade:\t" << a->getMinGradeToExecute() <<
	"\n\tis signed:\t" << a->getSigned() <<
	std::endl;
	return (o);
}