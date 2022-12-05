#pragma once
#include "Line.h"
#include "Shape.h"
class Rectangle :
    public Shape
{
private:
    Line* l1;
    Line* l2;
 
public:
    Rectangle();
    Rectangle(Line* line1, Line* line2);
    Rectangle(const Rectangle& cpy);
    virtual ~Rectangle();
    Shape* cloneObject() const;
    Line* getL1() const;
    Line* getL2() const;
    string getShapeName() const;
    friend ostream& operator << (ostream& out, const Rectangle& c)
    {
        out << "Line 1: ";
        c.l1->print();
        out << "Line 2:  ";
        c.l2->print();
        out << endl;
        return out;
    }

    void print() const;
};

