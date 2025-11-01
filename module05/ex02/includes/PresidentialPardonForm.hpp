#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& o);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& o);
	~PresidentialPardonForm();

protected:
	void executeAction() const;
};

#endif
