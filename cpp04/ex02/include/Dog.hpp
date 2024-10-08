#ifndef Dog_Hpp
#define Dog_Hpp

#include "Animal.hpp"

#include <string>

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &dog);
		void makeSound() const;
		void printBrainAddr() const;
		// overload operators
		Dog &operator=(const Dog &dog);
	private:
		Brain *brain;
};

#endif