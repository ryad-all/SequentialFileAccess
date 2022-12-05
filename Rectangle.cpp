#include "Rectangle.h"

Rectangle::Rectangle() : l1(nullptr), l2(nullptr)
{

}
Rectangle::Rectangle(Line* line1, Line* line2) : l1(line1), l2(line2)
{

}
Rectangle::Rectangle(const Rectangle& cpy) : l1(cpy.l1), l2(cpy.l2)
{

}
string Rectangle::getShapeName() const
{
	return "Rectangle";
}
Rectangle::~Rectangle()
{
	
	cout << "Object of class Rectangle has been destroyed.\n";
}
Shape* Rectangle::cloneObject() const
{
	return new Rectangle(*this);
}
Line* Rectangle::getL1() const
{
	return l1;
}
Line* Rectangle::getL2() const
{
	return l2;
}
void Rectangle::print() const
{
	cout << "\nThe class is " << this->getShapeName() << " and its points are  \n" << *this;
}