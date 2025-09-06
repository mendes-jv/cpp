#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
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

const char* Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade too high"; }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade too low"; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
