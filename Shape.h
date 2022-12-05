#pragma once
#include <iostream>
using namespace std;

class Shape
{
public:
	Shape();
	Shape(const Shape& copy);
	virtual ~Shape();
	virtual string getShapeName() const = 0;
	virtual Shape* cloneObject() const = 0;
	virtual void print() const = 0;
};

