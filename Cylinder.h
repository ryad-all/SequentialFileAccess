#pragma once
#include "Shape.h"
#include "Point.h"
class Cylinder :
    public Shape
{
private:
    Point* point;
    double radius;
    double height;

public:
    Cylinder();
    Cylinder(Point* Point, double radius, double height);
    Cylinder(const Cylinder& cpy);
    virtual ~Cylinder();

    Shape* cloneObject() const;
    Point* getPoint() const;
    double getRadius() const;
    double getHeight() const;

    void setPoint() const;
    void setRadius() const;
    void setHeight() const;

    string getShapeName() const;
    friend ostream& operator << (ostream& out, const Cylinder& c)
    {
        out << " has a point with coordinates ";
        c.point->print();
        out << " and a radius of " << c.radius << " and a height of " << c.height ;
        return out;
    }

    void print() const;
};

