#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <ctime> // for time()

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private :
	const std::string target;

	public :
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

#endif