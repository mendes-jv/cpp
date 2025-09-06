#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Intern someRandomIntern;
	AForm* f1 = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* f2 = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	AForm* f4 = someRandomIntern.makeForm("unknown form", "nobody");

	Bureaucrat boss("Boss", 1);
	Bureaucrat exec("Exec", 45);

	if (f1) { boss.signForm(*f1); exec.executeForm(*f1); boss.executeForm(*f1); }
	if (f2) { boss.signForm(*f2); boss.executeForm(*f2); }
	if (f3) { boss.signForm(*f3); boss.executeForm(*f3); }

	delete f1;
	delete f2;
	delete f3;
	delete f4;

	return 0;
}
