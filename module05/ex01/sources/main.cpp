#include <Bureaucrat.hpp>

int main() {
	Bureaucrat joao("João da Silva", 2);
	Bureaucrat victor("Victor Mendes", 149);

	std::cout << joao << std::endl;
	std::cout << victor << std::endl;

	joao.incrementGrade();
	std::cout << joao << std::endl;

	victor.decrementGrade();
	std::cout << victor << std::endl;

	try {
		Bureaucrat test_1("test - create high exception", 0);
		std::cout << test_1 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat test_2("test - create low exception 2", 151);
		std::cout << test_2 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	try {
		joao.incrementGrade();
	} catch (std::exception& exception) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	try {
		victor.decrementGrade();
	} catch (std::exception& exception) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << joao.getGrade() << std::endl;
	//joao.incrementGrade();

	return 0;
}
