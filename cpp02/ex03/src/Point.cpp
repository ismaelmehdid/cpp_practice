#include "../include/Point.hpp"

Point::Point() : _x(), _y()
{

}

Point::Point(const float x, const float y) : _x(x), _y(y)
{

}

Point::Point(const Point &toCopy) : _x(toCopy._x), _y(toCopy._y)
{

}

/* if needed
Point &Point::operator=(const Point &point)
{

}
*/

Point::~Point()
{

}

const Fixed &Point::get_x() const
{
	return _x;
}

const Fixed &Point::get_y() const
{
	return _y;
}

Fixed get_determinant(const Point &p1, const Point &p2, const Point &p3)
{
	return ((p1.get_x() - p3.get_x()) * (p2.get_y() - p3.get_y()) - (p2.get_x() - p3.get_x()) * (p1.get_y() - p3.get_y()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed(d1) = get_determinant(point, a, b); // P A B
	Fixed(d2) = get_determinant(point, b, c); // P B C
	Fixed(d3) = get_determinant(point, c, a) ; // P C A

	if (d1 == 0 || d2 == 0 || d3 == 0) // point is on one of the line
	{
		return false;
	}
	if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
	{
		return true;
	}
	return false;
}