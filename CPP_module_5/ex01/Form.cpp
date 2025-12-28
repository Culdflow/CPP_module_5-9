#include "Form.hpp"

Form::Form(): _name("Default Form"), _signed(false), _minGradeToSign(150), _minGradeToExecute(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(const std::string name, const int minGradeToSign, const int minGradeToExecute): _name(name), _signed(false), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute)
{
	std::cout << "Form Constructor Called" << std::endl;
	const int signGrade = this->getMinGradeToSign();
	const int executeGrade = this->getMinGradeToExecute();
	if (signGrade > 150 || executeGrade > 150)
		throw(Form::GradeTooLowException());
	else if( signGrade < 1 || executeGrade < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(Form& copy): _name(copy.getName()), _signed(false), _minGradeToSign(copy.getMinGradeToSign()), _minGradeToExecute(copy.getMinGradeToExecute())
{
	std::cout << "Form Copy Constructor Called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form Destructor Called" << std::endl;
}

Form&	Form::operator=(const Form& src)
{
	std::cout << "Form Assignation Operator Called" << std::endl;
	(void)src;
	return (*this);
}

const std::string	Form::getName( void )const
{
	return (this->_name);
}

bool	Form::getSigned( void )const
{
	return (this->_signed);
}

int	Form::getMinGradeToExecute( void )const
{
	return (this->_minGradeToExecute);
}

int	Form::getMinGradeToSign( void )const
{
	return (this->_minGradeToSign);
}

void	Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.get_grade() > this->getMinGradeToSign())
		throw(Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.get_name() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Form *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getMinGradeToSign() <<
	"\n\texec-grade:\t" << a->getMinGradeToExecute() <<
	"\n\tis signed:\t" << a->getSigned() <<
	std::endl;
	return (o);
}