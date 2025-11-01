#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "unit", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const std::string& t) : AForm("RobotomyRequestForm", t, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o) : AForm(o) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o){ AForm::operator=(o); return *this; }
RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeAction() const {
	std::cout << "* drilling noises *" << std::endl;
	int r = std::rand() % 2;
	if (r == 0) std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else std::cout << "Robotomy failed on " << getTarget() << std::endl;
}
