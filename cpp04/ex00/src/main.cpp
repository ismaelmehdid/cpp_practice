#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <iostream>

void notPolyMakeSound(const Animal anAnimal)
{
	anAnimal.makeSound();
}

int main()
{
	{
		std::cout << "=====---------- Using polymorphism -----------=====" << std::endl;
		const Animal* meta = new Animal();
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
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the ?? sound
		meta->makeSound();
		delete meta;
		delete i;
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