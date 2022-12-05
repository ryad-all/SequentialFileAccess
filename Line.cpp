#include "Line.h"


Line::Line() : p1(nullptr), p2(nullptr)
{

}

Line::Line(double x1, double y1, double x2, double y2) : p1(new Point(x1, y1)), p2(new Point(x2, y2))
{

}
Line::Line(const Line& cpy) : p1(cpy.p1) , p2(cpy.p2)
{

}
string Line::getShapeName() const
{
	return "Line";
}
Point* Line::getP1() const
{
	return p1;
}
Point* Line::getP2() const
{
	return p2;
}
Line::~Line()
{
	cout << "Object of class Line has been destroyed. \n";
}
Shape* Line::cloneObject() const
{
	return new Line(*this);
}
void Line::print() const
{
	cout << "The class is " << this->getShapeName() << " and data members are " << *this;
}