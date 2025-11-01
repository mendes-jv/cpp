#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "garden", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t) : AForm("ShrubberyCreationForm", t, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o) : AForm(o) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o){ AForm::operator=(o); return *this; }
ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::tree() {
	return
"       _-_        \n"
"    /~~   ~~\\    \n"
" /~~         ~~\\ \n"
"{               }\n"
" \\  _-     -_  / \n"
"   ~  \\\\ //  ~  \n"
"_- -   | | _- _  \n"
"  _ -  | |   -_  \n"
"      // \\\\      \n";
}

void ShrubberyCreationForm::executeAction() const {
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (ofs) {
		ofs << tree();
		ofs.close();
	}
}
