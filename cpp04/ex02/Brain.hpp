#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private :
	std::string _ideas[100];
	
	public :
	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain& operator=(const Brain& other);

	std::string* getIdeas();
	void printIdeas();
	void setIdeas(std::string idea);
};

#endif