#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat a("Alice", 30);
	Bureaucrat b("Bob", 140);

	Form f1("TopSecret", 20, 10);
	Form f2("Simple", 140, 140);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	a.signForm(f1);
	a.signForm(f2);
	b.signForm(f1);
	b.signForm(f2);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	return 0;
}
