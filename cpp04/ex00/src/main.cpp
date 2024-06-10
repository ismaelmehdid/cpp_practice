#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <iostream>

void notPolyMakeSound(const Animal anAnimal) // gotta use a reference or a pointer to call the right member function
{
	anAnimal.makeSound();
}

int main()
{
	{
		std::cout << "=====---------- Using polymorphism -----------=====" << std::endl;
		const Animal* meta = new Animal();
		// A dog is an Animal so we can store his address in an Animal ptr,
		// however we can't store an Animal object in a Dog ptr because an Animal is not necessarily a Dog
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound
		j->makeSound(); //will output the dog sound
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << '\n';
	{
		std::cout << "=====------- Not using polymorphism ----------=====" << std::endl;
		const WrongAnimal* wrong_cat = new WrongCat();

		std::cout << wrong_cat->getType() << " " << std::endl;
		wrong_cat->makeSound();
		delete wrong_cat; // destructor of WrongAnimal because it's not using polymorphism so it consider wrong_cat as an Animal and not a Cat
	}
		std::cout << '\n';
	{
		const Cat my_cat;
		const Dog my_dog;
		my_cat.makeSound();
		my_dog.makeSound();

		notPolyMakeSound(my_cat);
		notPolyMakeSound(my_dog);
	}
	return 0;
}