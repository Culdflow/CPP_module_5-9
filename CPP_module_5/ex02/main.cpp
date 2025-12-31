#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat *harry = new Bureaucrat(150, "harry");

	for (int i = 0; i < 1; i++)
	{
		try
		{
			harry->decr_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "[ERROR]: ";
			std::cerr << e.what() << '\n';
		}
		std::cout << harry;
	}
	delete harry;
	Bureaucrat *gerald = new Bureaucrat(130, "gerald");

	for (int i = 0; i < 21; i++)
	{
		try
		{
			gerald->decr_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "[ERROR]: ";
			std::cerr << e.what() << '\n';
		}
		std::cout << gerald;
	}
	delete gerald;
	Bureaucrat *alex = new Bureaucrat(50, "alex");

	for (int i = 0; i < 50; i++)
	{
		try
		{
			alex->incr_grade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << "[ERROR]: ";
			std::cerr << e.what() << '\n';
		}
		std::cout << alex;
	}
	delete alex;
	try
	{
		Bureaucrat *dominique = new Bureaucrat(0, "dominique");
		delete dominique;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "[ERROR]: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat *lilian = new Bureaucrat(151, "lilian");
		delete lilian;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "[ERROR]: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat *christian = new Bureaucrat(-36, "christian");
		delete christian;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "[ERROR]: ";
		std::cerr << e.what() << '\n';
	}
	///////////////////////////////////////////////////////
	// AForm *acceptForm = new AForm("IDK", 120, 150);
	AForm *shrub = new ShrubberyCreationForm("an old man");
	Bureaucrat *arnold = new Bureaucrat(100, "Arnold");

	arnold->executeForm(*shrub);
	delete shrub;
	delete arnold;

	AForm *robo = new RobotomyRequestForm("macron");
	Bureaucrat *dobby = new Bureaucrat(30, "Dobby");

	dobby->executeForm(*robo);
	delete robo;
	delete dobby;

	AForm *pres = new PresidentialPardonForm("Luigi mangione");
	Bureaucrat *sir = new Bureaucrat(1, "Sir");

	sir->executeForm(*pres);
	delete pres;
	delete sir;
}