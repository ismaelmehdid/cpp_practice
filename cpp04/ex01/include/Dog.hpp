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
		// overload operators
		Dog &operator=(const Dog &dog);
};

#endif