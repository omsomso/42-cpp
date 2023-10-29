#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"

int main(void) {
	std::cout << "----Required tests----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
    meta->makeSound();

	delete(meta);
	delete(i);
	delete(j);

	std::cout << std::endl << "----Wrong tests----" << std::endl;
	const WrongAnimal* meta_wrong = new WrongAnimal();
	const WrongAnimal* i_wrong = new WrongCat();

	std::cout << i_wrong->getType() << " " << std::endl;
	i_wrong->makeSound(); //will output the default animal sound
    meta_wrong->makeSound();

	delete(meta_wrong);
	delete(i_wrong);

	std::cout << std::endl << "----My tests----" << std::endl;
	Animal some_critter;
	Dog barker;
	Cat filomena;
	Dog another_barker;

	some_critter.makeSound();
	barker.makeSound();
	filomena.makeSound();
	another_barker = barker;
	another_barker.makeSound();

	return (0);
}
