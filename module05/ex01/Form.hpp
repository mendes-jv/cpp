#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
public:
	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	const std::string& getName() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
	public: const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public: const char* what() const throw();
	};

private:
	void validateGrade(int g);
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
