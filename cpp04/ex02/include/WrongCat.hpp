#ifndef WrongCat_Hpp
#define WrongCat_Hpp

#include "WrongAnimal.hpp"

#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &wrong_cat);
		void makeSound() const;
		// overload operators
		WrongCat &operator=(const WrongCat &wrong_cat);
};

#endif