#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *harry = new Bureaucrat(150, "harry");

	for (int i = 0; i < 150; i++)
	{
		try
		{
			harry->decr_grade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << harry << std::endl;
	}
}