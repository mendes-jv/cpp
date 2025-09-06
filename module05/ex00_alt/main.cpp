#include "Bureaucrat.hpp"

int main() {
	Bureaucrat a("Alice", 2);
	Bureaucrat b("Bob", 149);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	a.incrementGrade();
	std::cout << a << std::endl;

	b.decrementGrade();
	std::cout << b << std::endl;

	try {
		Bureaucrat c("WrongHigh", 0);
		std::cout << c << std::endl;
	} catch (std::exception& e) {
		std::cout << "Failed: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d("WrongLow", 151);
		std::cout << d << std::endl;
	} catch (std::exception& e) {
		std::cout << "Failed: " << e.what() << std::endl;
	}

	try {
		a.incrementGrade();
	} catch (std::exception& e) {
		std::cout << "Increment failed: " << e.what() << std::endl;
	}
	return 0;
}
