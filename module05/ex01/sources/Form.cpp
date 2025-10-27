#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) : _name(name), _signed(false),
_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	validateGrade(_gradeToSign);
	validateGrade(_gradeToExecute);
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed),
_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if(this!=&other) _signed=other._signed;
	return *this;
}

Form::~Form(){}

const std::string& Form::getName() const { return _name; }

bool Form::isSigned() const { return _signed; }

int Form::getGradeToSign() const { return _gradeToSign; }

int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::validateGrade(const int grade) {
	if(grade < 1) throw GradeTooHighException();
	if(grade > 150) throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& object) {
	if (object.getGrade() <= _gradeToSign) _signed = true;
	else throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){ return "Grade too high for for Form"; }
const char* Form::GradeTooLowException::what() const throw(){ return "Grade too low for Form"; }

std::ostream& operator<<(std::ostream& os, const Form& object) {
	os << "Form " << object.getName()
		<< ":\n signed=" << (object.isSigned() ? "yes" : "no")
		<< ", signGrade=" << object.getGradeToSign()
		<< ", execGrade=" << object.getGradeToExecute()
		<< std::endl;
	return os;
}
