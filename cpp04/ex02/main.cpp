#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void) {

	// Animal compilationError;

	std::cout << "----Leak test----" << std::endl << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl << "----Array test----" << std::endl << std::endl;

	int nb_animals = 4;
	Animal **animalArray;
	animalArray = new Animal*[nb_animals];

	for (int i = 0; i < nb_animals; i++) {
		if (i % 2 == 0)
			animalArray[i] = new Dog();
		else
			animalArray[i] = new Cat();
	}
	for (int i = 0; i < nb_animals; i++)
		animalArray[i]->makeSound();
	for (int i = 0; i < nb_animals; i++)
		delete animalArray[i];
	delete[] animalArray;

	// Deep copy with Cat objects

	std::cout << std::endl << "----Deep copy test----" << std::endl << std::endl;
	
	std::cout << "--Source cat with ideas--" << std::endl;
	Cat* copycat_src = new Cat();
	copycat_src->setBrain();
	copycat_src->printBrain();
	
	std::cout << "--Destination cat without ideas--" << std::endl;
	Cat* copycat_dst = new Cat();
	copycat_dst->printBrain();

	std::cout << "--Copying source cat to destination cat--" << std::endl;
	*copycat_dst = *copycat_src;
	copycat_dst->printBrain();
	delete copycat_src;
	
	std::cout << "--Destination cat still has all ideas : --" << std::endl;
	copycat_dst->printBrain();
	delete copycat_dst;

	return (0);
}
