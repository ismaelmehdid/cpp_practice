#ifndef WrongAnimal_Hpp
#define WrongAnimal_Hpp

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const std::string &custom_type);
		WrongAnimal(const WrongAnimal &wrong_animal);
		std::string getType() const;
		// not setting makeSound as virtual, so if a WrongCat object call it's member function makeSound,
		// it will call the WrongAnimal function implementation
		void makeSound() const;
		// overload operators
		WrongAnimal &operator=(const WrongAnimal &wrong_animal);
	protected:
		std::string type;
};

#endif