#pragma once
#include "Element.h"
#include <cstring>
#include <iostream>

class Triangle;

class Point :public Element
{
public:
	Point(); // Consturctor
	Point(double, double, double); // Consturctor
	Point(const Point& rhs); // Copy Consturctor

	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

	double getX() const; // Get X
	double getY() const; // Get Y
	double getZ() const; // Get Z

	void setX(double x); // Set X
	void setY(double y); // Set Y
	void setZ(double z); // Set Z
	Point& operator=(const Point&);

	bool operator==(Point& rhs); // Compare two points
	bool operator<(Triangle& tr) const;
	bool operator>(Triangle& tr) const;


protected:
	double x; // X
	double y; // Y
	double z; // Z
};
std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream& , Point& );
