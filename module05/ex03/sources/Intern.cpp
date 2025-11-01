#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

typedef AForm* (*CreateFn)(const std::string&);

static AForm* createShrub(const std::string& t) { return new ShrubberyCreationForm(t); }
static AForm* createRobo(const std::string& t) { return new RobotomyRequestForm(t); }
static AForm* createPardon(const std::string& t) { return new PresidentialPardonForm(t); }

Intern::Intern() {}
Intern::Intern(const Intern&){ }
Intern& Intern::operator=(const Intern&){ return *this; }
Intern::~Intern(){}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	CreateFn creators[3] = { &createShrub, &createRobo, &createPardon };

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Intern couldn't find form named \"" << formName << "\"" << std::endl;
	return 0;
}
