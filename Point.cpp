#include "Point.h"


Point::Point() : x(0), y(0)
{

}
Point::Point(double a, double b) : x(a), y(b)
{

}

Point::~Point()
{
	cout << "Object of class Point has been destroyed. \n";
}
void Point::setX(double a)

{
	x = a;
}
void Point::setY(double a)
{
	y = a;
}

double Point::getX() const
{	
	return x;
}
string Point::getShapeName() const
{
	return "Point";
}
double Point::getY() const
{
	return y;
}
Point Point::getPoint() const
{
	return *this;
}
Point::Point(const Point& copy) : x(copy.x), y(copy.y)
{
}

Shape* Point::cloneObject() const
{
	return new Point(*this);
}

void Point::print() const
{
	cout << "\The class is " << this->getShapeName() << " and its coordinates are: " << *this;
}

