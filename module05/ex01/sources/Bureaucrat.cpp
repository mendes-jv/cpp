#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) { validateGrade(_grade); }

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) _grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::validateGrade(int g) {
	if (g < 1) throw GradeTooHighException();
	if (g > 150) throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
	validateGrade(_grade - 1);
	_grade -= 1;
}

void Bureaucrat::decrementGrade() {
	validateGrade(_grade + 1);
	_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high for Bureaucrat"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low for Bureaucrat"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}
