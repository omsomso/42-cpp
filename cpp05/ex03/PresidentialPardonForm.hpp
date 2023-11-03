#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public  Form {
	private :
	const std::string target;

	public :
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

#endif