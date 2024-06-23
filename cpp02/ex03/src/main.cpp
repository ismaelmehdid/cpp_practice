#include "../include/Point.hpp"
#include "../include/Fixed.hpp"

#include <iostream>

int main(void)
{
	{
		Point a(1, 2);
		Point b(5, 3);
		Point c(4, 8);
		Point p(4, 4);

		if (bsp(a, b, c, p)) {
			std::cout << "The point P is inside the triangle ABC." << std::endl;
		} else {
			std::cout << "The point P is not inside the triangle ABC." << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Point a(1, 2);
		Point b(5, 3);
		Point c(4, 8);
		Point p(2, 2);

		if (bsp(a, b, c, p)) {
			std::cout << "The point P is inside the triangle ABC." << std::endl;
		} else {
			std::cout << "The point P is not inside the triangle ABC." << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Point a(1, 2);
		Point b(5, 3);
		Point c(4, 8);
		Point p(2, 4);

		if (bsp(a, b, c, p)) {
			std::cout << "The point P is inside the triangle ABC." << std::endl;
		} else {
			std::cout << "The point P is not inside the triangle ABC." << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Point a(1, 2);
		Point b(5, 3);
		Point c(4, 8);
		Point p(2, 3);

		if (bsp(a, b, c, p)) {
			std::cout << "The point P is inside the triangle ABC." << std::endl;
		} else {
			std::cout << "The point P is not inside the triangle ABC." << std::endl;
		}
	}
}