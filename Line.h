#pragma once
#include "Shape.h"
#include "Point.h"

class Line :
    public Shape
{
private: 
    Point* p1;
    Point* p2;
    
public: 
    Line();
    Line(double x1, double y1, double x2, double y2);
    Line(const Line& cpy);
    virtual ~Line();
    Shape* cloneObject() const;
    Point* getP1() const;
    Point* getP2() const;

    string getShapeName() const;

    friend ostream& operator << (ostream& out, const Line& c)
    {
        out << "(" << c.p1->getX() << " , " << c.p1->getY() << ")" << " and " << "("<< c.p2->getX() << " , " << c.p2->getY()<< ")" << endl;
        return out;
    }

    void print() const;
};

