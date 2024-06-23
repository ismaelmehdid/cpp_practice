#pragma once

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &toCopy);
		//Point &operator=(const Point &point); if needed
		~Point();

		const Fixed &get_x() const;
		const Fixed &get_y() const;
	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);