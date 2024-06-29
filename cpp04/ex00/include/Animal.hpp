#ifndef Animal_Hpp
#define Animal_Hpp

#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const std::string &custom_type);
		Animal(const Animal &animal);
		std::string getType() const;
		virtual void makeSound() const;
		// overload operators
		Animal &operator=(const Animal &animal);
	protected:
		std::string type;
};

#endif