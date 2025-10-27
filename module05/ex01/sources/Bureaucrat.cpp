#include <Bureaucrat.hpp>
#include <Form.hpp>

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name), _grade(grade)
{
	validateGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) _grade = other.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::validateGrade(const int grade) {
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
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

void Bureaucrat::signForm(Form& object) const {
	try {
		object.beSigned(*this);
		std::cout << _name << " signed " << object.getName() << std::endl;
	} catch (std::exception& exception) {
		std::cout << _name << " couldn't sign " << object.getName() << " because " << exception.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object) {
	os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return os;
}
