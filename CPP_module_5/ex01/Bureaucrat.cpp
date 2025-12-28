#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Basic Bureaucrat"), _grade(150)
{
	std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat( int grade, std::string name ): _name(name)
{
	std::cout << "Bureaucrat Constructor Called" << std::endl;
	this->set_grade(grade);
}

Bureaucrat::Bureaucrat( Bureaucrat& copy )
{
	std::cout << "Bureaucrat Copy Constructor Called" << std::endl;
	this->_name = copy.get_name() + "_copy";
	this->set_grade(copy.get_grade());
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destrucor Called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& src )
{
	this->_name = src.get_name();
	this->_grade = src.get_grade();
	return (*this);
}

std::string	Bureaucrat::get_name()const
{
	return (this->_name);
}

int	Bureaucrat::get_grade()const
{
	return (this->_grade);
}

void	Bureaucrat::set_grade( int grade )
{
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	else if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

void	Bureaucrat::incr_grade( void )
{
	this->set_grade(this->get_grade() - 1);
}

void	Bureaucrat::decr_grade( void )
{
	this->set_grade(this->get_grade() + 1);
}

void	Bureaucrat::signForm( Form& form )
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->get_name() << " couldn’t sign " << form.getName() << " because his grade is too low" << std::endl;
		return ;
	}
	std::cout << this->get_name() << " signed " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->get_name() << ":\n\tgrade: " << a->get_grade() << std::endl;
	return (o);
}