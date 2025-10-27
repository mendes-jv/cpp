#include <Bureaucrat.hpp>
#include <Form.hpp>

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
		Bureaucrat test1("test - create high exception", 0);
		std::cout << test1 << std::endl;
	} catch (std::exception& exception) {
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	try {
		Bureaucrat test2("test - create low exception 2", 151);
		std::cout << test2 << std::endl;
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
		std::cout << "Exception: " << exception.what() << std::endl << std::endl;
	}

	Form file1("File 1", 42, 23);
	Form file2("File 2", 150, 42);

	std::cout << file1 << std::endl;
	std::cout << file2 << std::endl;

	joao.signForm(file1);
	joao.signForm(file2);
	victor.signForm(file1);
	victor.signForm(file2);

	std::cout << std::endl << file1 << std::endl;
	std::cout << file2 << std::endl;

	return 0;
}
