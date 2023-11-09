#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <ctime> // for time()

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public :
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm &other);

	void execute(Bureaucrat const& executor) const ;
};

#endif