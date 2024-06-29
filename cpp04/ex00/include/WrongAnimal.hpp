#ifndef WrongAnimal_Hpp
#define WrongAnimal_Hpp

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal(const std::string &custom_type);
		WrongAnimal(const WrongAnimal &wrong_animal);
		std::string getType() const;
		void makeSound() const; // not virtual
		// overload operators
		WrongAnimal &operator=(const WrongAnimal &wrong_animal);
	protected:
		std::string type;
};

#endif