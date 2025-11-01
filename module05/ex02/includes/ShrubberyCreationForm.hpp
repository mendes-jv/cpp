#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& o);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& o);
	~ShrubberyCreationForm();

protected:
	void executeAction() const;

private:
	static std::string tree();
};

#endif
