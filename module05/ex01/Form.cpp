#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("GenericForm"), _signed(false), _signGrade(150), _execGrade(150) {}
Form::Form(const std::string& name, int s, int e) : _name(name), _signed(false), _signGrade(s), _execGrade(e) {
	validateGrade(_signGrade); validateGrade(_execGrade);
}
Form::Form(const Form& o) : _name(o._name), _signed(o._signed), _signGrade(o._signGrade), _execGrade(o._execGrade) {}
Form& Form::operator=(const Form& o){ if(this!=&o){ _signed=o._signed; } return *this; }
Form::~Form(){}

const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

void Form::validateGrade(int g){ if(g<1) throw GradeTooHighException(); if(g>150) throw GradeTooLowException(); }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _signGrade) _signed = true;
	else throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){ return "Form grade too high"; }
const char* Form::GradeTooLowException::what() const throw(){ return "Form grade too low"; }

std::ostream& operator<<(std::ostream& os, const Form& f){
	os << "Form \"" << f.getName() << "\" [signed=" << (f.isSigned()?"yes":"no")
	   << ", signGrade=" << f.getSignGrade() << ", execGrade=" << f.getExecGrade() << "].";
	return os;
}
