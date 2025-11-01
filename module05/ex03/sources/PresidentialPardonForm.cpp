#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "citizen", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string& t) : AForm("PresidentialPardonForm", t, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o) : AForm(o) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o){ AForm::operator=(o); return *this; }
PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::executeAction() const {
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
