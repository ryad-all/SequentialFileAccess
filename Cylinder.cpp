#include "Cylinder.h"


Cylinder::Cylinder() : point(nullptr), radius(0), height(0)
{

}
Cylinder::Cylinder(Point* p, double r, double h) : point(p), radius(r), height(h)
{

}
Cylinder::Cylinder(const Cylinder& cpy) : point(cpy.point), radius(cpy.radius), height(cpy.height)
{

}
Cylinder::~Cylinder()
{
	
	cout << "Object of class Cylinder has been destroyed. \n";
}
Shape* Cylinder::cloneObject() const
{
	return new Cylinder(*this);
}
Point* Cylinder::getPoint() const
{
	return point;
}
double Cylinder::getRadius() const
{
	return radius;
}
double Cylinder::getHeight() const
{
	return height;
}

void Cylinder::setPoint() const
{
	
}
void Cylinder::setRadius() const
{

}
void Cylinder::setHeight() const
{

}

string Cylinder::getShapeName() const
{
	return "Cylinder";
}


void Cylinder::print() const
{
	cout << "\nThe " << this->getShapeName() << *this << endl;
}