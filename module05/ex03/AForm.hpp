#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(const std::string& name, const std::string& target, int signGrade, int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	const std::string& getTarget() const;
	bool isSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(const Bureaucrat& b);
	void execute(Bureaucrat const& executor) const;

	class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
	class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };
	class NotSignedException    : public std::exception { public: const char* what() const throw(); };

protected:
	virtual void executeAction() const = 0;

private:
	void validateGrade(int g);

	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
	std::string _target;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
