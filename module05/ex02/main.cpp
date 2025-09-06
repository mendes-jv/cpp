#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Middle", 70);
	Bureaucrat low("Low", 150);

	ShrubberyCreationForm s("home");
	RobotomyRequestForm r("Bender");
	PresidentialPardonForm p("Arthur Dent");

	std::cout << s << std::endl;
	std::cout << r << std::endl;
	std::cout << p << std::endl;

	low.signForm(s);
	mid.signForm(r);
	boss.signForm(p);

	low.executeForm(s);
	mid.executeForm(r);
	boss.executeForm(p);

	boss.executeForm(s);
	boss.executeForm(r);
	return 0;
}
