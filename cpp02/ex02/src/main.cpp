#include "../include/Fixed.hpp"

#include <iostream>
int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed a(42);
		Fixed b(32);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		if (a > b)
		{
			std::cout << "a is larger than b" << std::endl;
		}
		else
		{
			std::cout << "b is larger than b" << std::endl;
		}

		if (a < b)
		{
			std::cout << "b is larger than b" << std::endl;
		}
		else
		{
			std::cout << "a is larger than b" << std::endl;
		}

		if (a <= b)
		{
			std::cout << "b is larger than b" << std::endl;
		}
		else
		{
			std::cout << "a is larger than b" << std::endl;
		}

		if (a >= b)
		{
			std::cout << "a is larger than b" << std::endl;
		}
		else
		{
			std::cout << "b is larger than b" << std::endl;
		}

		Fixed c(42);
		Fixed d(42);

		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;

		if (c == d)
		{
			std::cout << "c is equal to d" << std::endl;
		}
		else if (c != d)
		{
			std::cout << "c is different to d" << std::endl;
		}

		Fixed e(42);
		Fixed f(43);

		std::cout << "e = " << e << std::endl;
		std::cout << "f = " << f << std::endl;

		if (e == f)
		{
			std::cout << "e is equal to f" << std::endl;
		}
		else if (e != f)
		{
			std::cout << "e is different to f" << std::endl;
		}
	{
		Fixed a(32);
		Fixed b(1.5f);

		std::cout << (a + b).toFloat() << std::endl;

		std::cout << (a - b).toFloat() << std::endl;

		std::cout << (a * b).toFloat() << std::endl;

		std::cout << (a / b).toFloat() << std::endl;
	}
	}
	return 0;
}