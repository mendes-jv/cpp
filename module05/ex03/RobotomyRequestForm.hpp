#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& o);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& o);
	~RobotomyRequestForm();

protected:
	void executeAction() const;
};

#endif
