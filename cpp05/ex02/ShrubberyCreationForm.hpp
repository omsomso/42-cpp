#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream> // for files

#include "Form.hpp"

# define ASCIITREE ".\n                                              .         ;  \n                 .              .              ;%     ;;   \n                   ,           ,                :;%  %;   \n                    :         ;                   :;%;'     .,   \n           ,.        %;     %;            ;        %;'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n               ;%;      %;        ;%;        % ;%;  ,%;'\n                `%;.     ;%;     %;'         `;%%;.%;'\n                 `:;%.    ;%%. %@;        %; ;@%;%'\n                    `:%;.  :;bd%;          %;@%;'\n                      `@%:.  :;%.         ;@@%;'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . '         \n                                %@@@o%;:(.,'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..\n"


class ShrubberyCreationForm : public Form {
	private :
	const std::string target;

	public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	virtual std::string getTarget() const;
	static void execute(std::string target);
};

#endif