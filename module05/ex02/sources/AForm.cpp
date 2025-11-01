#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("AbstractForm"), _signed(false), _signGrade(150), _execGrade(150), _target("target") {}
AForm::AForm(const std::string& n, const std::string& t, int s, int e)
: _name(n), _signed(false), _signGrade(s), _execGrade(e), _target(t) {
	validateGrade(_signGrade); validateGrade(_execGrade);
}
AForm::AForm(const AForm& o)
: _name(o._name), _signed(o._signed), _signGrade(o._signGrade), _execGrade(o._execGrade), _target(o._target) {}
AForm& AForm::operator=(const AForm& o){
	if(this!=&o){ _signed=o._signed; _target=o._target; }
	return *this;
}
AForm::~AForm(){}

const std::string& AForm::getName() const { return _name; }
const std::string& AForm::getTarget() const { return _target; }
bool AForm::isSigned() const { return _signed; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::validateGrade(int g){ if(g<1) throw GradeTooHighException(); if(g>150) throw GradeTooLowException(); }

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _signGrade) _signed = true;
	else throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!_signed) throw NotSignedException();
	if (executor.getGrade() > _execGrade) throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw(){ return "Form grade too high"; }
const char* AForm::GradeTooLowException::what() const throw(){ return "Form grade too low"; }
const char* AForm::NotSignedException::what() const throw(){ return "Form not signed"; }

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << "AForm \"" << f.getName() << "\" [target=" << f.getTarget()
	   << ", signed=" << (f.isSigned()?"yes":"no")
	   << ", signGrade=" << f.getSignGrade()
	   << ", execGrade=" << f.getExecGrade() << "].";
	return os;
}
