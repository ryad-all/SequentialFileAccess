#include "Line.h"
#include "Rectangle.h"
#include "Cylinder.h"
#include <fstream>
#include <string>
#include <vector>
int main()
{
	string fileName = "TextFile.txt";
	//creation of objects --------------------------
	Shape* baseArray[6];
	Shape* point = new Point(2.2, 3.4);
	Shape* point1 = new Point(3.1, 5.8);
	Shape* line = new Line(3.3, 5.7, 3.2, 4.2);
	Shape* line1 = new Line(2.6, 2.3, 1.8, 4.8);
	Shape* line2 = new Line(2.0, 2.3, 1.8, 4.8);
	Shape* rectangle = new Rectangle(static_cast<Line*>(line), static_cast<Line*>(line1));
	Shape* cylinder = new Cylinder(static_cast<Point*>(point), 1.1, 1.3);

	//loading base pointer ---------------------------
	baseArray[0] = point->cloneObject();
	baseArray[1] = point1->cloneObject();
	baseArray[2] = line->cloneObject();
	baseArray[3] = line1->cloneObject();
	baseArray[4] = rectangle->cloneObject();
	baseArray[5] = cylinder->cloneObject();
	
	//writing mode -----------------------------------
	ofstream out;
	try
	{
		out.open(fileName, ios::out); // write mode
		if (!out)
		{
			throw "File could not be opened.";
		}
		if (out)
		{
			cout << "Successful file creation. " << endl;
		}
		for (int i = 0; i < 6; i++)
		{
			if (baseArray[i]->getShapeName() == "Point")
			{
				out << baseArray[i]->getShapeName() << " " << dynamic_cast<Point*>(baseArray[i])->getX() << " " << dynamic_cast<Point*>(baseArray[i])->getY() << endl;
			}
			if (baseArray[i]->getShapeName() == "Line")
			{
				out << baseArray[i]->getShapeName() << " " << dynamic_cast<Line*>(baseArray[i])->getP1()->getX() << " " << dynamic_cast<Line*>(baseArray[i])->getP1()->getY()
					<< " " << dynamic_cast<Line*>(baseArray[i])->getP2()->getX() << " " << dynamic_cast<Line*>(baseArray[i])->getP2()->getY() << endl;
			}
			if (baseArray[i]->getShapeName() == "Rectangle")
			{
				out << baseArray[i]->getShapeName() << " " << dynamic_cast<Rectangle*>(baseArray[i])->getL1()->getP1()->getX() << " " << dynamic_cast<Rectangle*>(baseArray[i])->getL1()->getP1()->getY()
					<< " " << dynamic_cast<Rectangle*>(baseArray[i])->getL1()->getP2()->getX() << " " << dynamic_cast<Rectangle*>(baseArray[i])->getL1()->getP2()->getY()
					<< " " << dynamic_cast<Rectangle*>(baseArray[i])->getL2()->getP1()->getX() << " " << dynamic_cast<Rectangle*>(baseArray[i])->getL2()->getP1()->getY()
					<< " " << dynamic_cast<Rectangle*>(baseArray[i])->getL2()->getP2()->getX() << " " << dynamic_cast<Rectangle*>(baseArray[i])->getL2()->getP2()->getY() << endl;
			}
			if (baseArray[i]->getShapeName() == "Cylinder")
			{
				out << baseArray[i]->getShapeName() << " " << dynamic_cast<Cylinder*>(baseArray[i])->getPoint()->getX() << " " << dynamic_cast<Cylinder*>(baseArray[i])->getPoint()->getY() 
					<< " " << dynamic_cast<Cylinder*>(baseArray[i])->getRadius() << " " << dynamic_cast<Cylinder*>(baseArray[i])->getHeight() << endl;
			}
		}		
	}
	catch(char* str)
	{
		cout << str << endl;
	}
	out.close(); // closing file 
	//--------------------------------- 
	
	string strArray[6]; //collecting class name
	string file;
	int counter;
	counter = 0;
	ifstream infile;
	Shape* baseArray2[6];
	try
	{
		infile.open(fileName, ios::in);// read mode 
		if (!infile)
		{
			throw "File could not be opened. \n";
		}
		if (infile)
		{
			cout << "Successful file access. " << endl;
		}

		int n = 0;
		cout << "\nReading the first string of each line: \n";
		while (getline(infile, file))
		{
			strArray[n] = file;
			cout << "Data read : " << endl;
			cout << strArray[n] << endl;
			n++;
		}
		cout << "Printing read data: \n\n";
		// now we can create object from read data
		
		int m = 0;
		for (int i = 0; i < 6; i++)
		{
			
			if (strArray[i].substr(0, 5) == "Point")
			{
				cout << endl << strArray[i].substr(0, 5) ;
				string a, b;
				a = strArray[i].substr(6, 3);
				b =  strArray[i].substr(10, 3);
				baseArray2[m] = new Point(stod(a), stod(b));
				baseArray2[m]->print();
			}
			if (strArray[i].substr(0, 4) == "Line")
			{
				cout << endl <<strArray[i].substr(0, 4) ;
				string a, b,c,d;
				a = strArray[i].substr(5, 3);
				b = strArray[i].substr(9, 3);
				c = strArray[i].substr(13, 3);
				d = strArray[i].substr(17, 3);
				baseArray2[m] = new Line(stod(a), stod(b), stod(c), stod(d));
				baseArray2[m]->print();
			}
			if (strArray[i].substr(0, 9) == "Rectangle")
			{
				cout << endl << strArray[i].substr(0, 9);
				string a, b, c, d, e,f,g,h;
				a = strArray[i].substr(10, 3);
				b = strArray[i].substr(14, 3);
				c = strArray[i].substr(18, 3);
				d = strArray[i].substr(22, 3);
				e = strArray[i].substr(26, 3);
				f = strArray[i].substr(30, 3);
				g = strArray[i].substr(34, 3);
				h = strArray[i].substr(38, 3);
				Shape* l1 = new Line(stod(a), stod(b), stod(c), stod(d));
				Shape* l2= new Line(stod(e), stod(f), stod(g), stod(h));
				baseArray2[m] = new Rectangle(static_cast<Line*>(l1),static_cast<Line*>(l2));
				baseArray2[m]->print();
				delete l1, l2;
			}
			if (strArray[i].substr(0, 8) == "Cylinder")
			{
				cout << endl <<strArray[i].substr(0, 8);
				string a, b, c,d;
				a = strArray[i].substr(9, 3);
				b = strArray[i].substr(13, 3);
				c = strArray[i].substr(17, 3);
				d = strArray[i].substr(21,3);
				Point* p = new Point(stod(a), stod(b));
				baseArray2[m] = new Cylinder(static_cast<Point*>(p),stod(c), stod(d));
				baseArray2[m]->print();
				delete p;
			}

			m++;
		}
	}
	catch (string str)
	{
		cout << str << endl;
	}
	cout << "\nCalling destructors. \n\n";
	for (int i =0;i<6;i++)
	{
		delete baseArray[i];
		delete baseArray2[i];
	}
	delete point, point1, line, line1, line2, rectangle, cylinder;
	return 0;
}