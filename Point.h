#pragma once
#include "Shape.h"
#include "fstream"

class Point :
    public Shape
{
private :
    double x;
    double y;
    string name;
public: 
    Point();
    
    Point(double, double);
    ~Point();
    void setX(double);
    void setY(double);
    string getShapeName() const;
    Point(const Point&);
    double getX() const;
    double getY() const;
    Shape* cloneObject() const;
    Point getPoint() const;
    friend ostream& operator << (ostream& out, const Point& c)
    {
        out << "(" << c.x << " , " << c.y << ")" << endl;
        return out;
    }
    void print() const; 
};

