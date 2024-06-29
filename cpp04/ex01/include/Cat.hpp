#ifndef Cat_Hpp
#define Cat_Hpp

#include "Animal.hpp"

#include <string>

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &cat);
		void makeSound() const;
		void printBrainAddr() const;
		// overload operators
		Cat &operator=(const Cat &cat);
	private:
		Brain *brain;
};

#endif