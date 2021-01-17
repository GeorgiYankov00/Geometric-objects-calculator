#include "Tetrahedron.h"
#include"Vector.h"
#include"Point.h"
#include"Line.h"
#include"Segment.h"
#include <math.h>


Tetrahedron::Tetrahedron() {};

Tetrahedron::Tetrahedron(Point& first, Point& second, Point& third, Point& forth) : p1(first), p2(second), p3(third), p4(forth)
{
	try {
		this->validate();
	}
	catch (EqualPointException& e) {
		cerr << e.msgTr() << endl;
	}
}

Tetrahedron::Tetrahedron(const Tetrahedron& rhs) : p1(rhs.p1), p2(rhs.p2), p3(rhs.p3), p4(rhs.p4)
{
	try {
		this->validate();
	}
	catch (EqualPointException& e) {
		cerr << e.msgTr() << endl;
	}
}

Tetrahedron::~Tetrahedron() {}

bool Tetrahedron::isRegular()
{
	Segment l1(this->p1, this->p2);
	Segment l2(this->p1, this->p3);
	Segment l3(this->p1, this->p4);
	Segment l4(this->p2, this->p3);
	Segment l5(this->p2, this->p4);
	Segment l6(this->p3, this->p4);

	if ((l1.getLength() == l2.getLength() == l3.getLength() == l4.getLength() == l5.getLength() == l6.getLength() == true)) {
	
    return true;
	}

	else
	{
		return false;
	}
	
}

float Tetrahedron::getSurface()
{
	Triangle a;
	a.makeTriangleFromPoints(this->p1, this->p2, this->p3);

	Triangle b;
	b.makeTriangleFromPoints(this->p1, this->p2, this->p4);

	Triangle c;
	c.makeTriangleFromPoints(this->p1, this->p3, this->p4);

	Triangle d;
	d.makeTriangleFromPoints(this->p2, this->p3, this->p4);

	return a.TriangleArea() + b.TriangleArea() + c.TriangleArea() + d.TriangleArea();
}

float Tetrahedron::getVolume(Point& p1, Point& p2, Point& p3, Point& p4)
{
	Vector a(p1, p2);
	Vector b(p1, p3);
	Vector c(p1, p4);

	return abs(a(b, c) / 6);
}

const Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs)
{
	if (this != &rhs)
	{
		this->p1 = rhs.p1;
		this->p2 = rhs.p2;
		this->p3 = rhs.p3;
		this->p4 = rhs.p4;
	}

	return *this;
}

//Check if a point is inside tetrahedron
bool Tetrahedron::operator<(const Point& point) const
{
	//Coordinates of th vertices of the tetrahedron
	double x1 = p1.getX(); double y1 = p1.getY(); double z1 = p1.getZ();
	double x2 = p2.getX(); double y2 = p2.getY(); double z2 = p2.getZ();
	double x3 = p3.getX(); double y3 = p3.getY(); double z3 = p3.getZ();
	double x4 = p4.getX(); double y4 = p4.getY(); double z4 = p4.getZ();

	double x = point.getX(); double y = point.getY(); double z = point.getZ();

	//Calculating determinants 
	double D0 = (x1 * y2 * z3) + (x2 * y3 * z4) + (x3 * y4 * z1) + (x4 * y1 * z2) - (z2 * y3 * x4) - (z1 * y2 * x3) - (y1 * x2 * z4) - (x1 * y4 * z3);
	double D1 = (x * y2 * z3) + (x2 * y3 * z4) + (x3 * y4 * z) + (x4 * y * z2) - (z2 * y3 * x4) - (z * y2 * x3) - (y * x2 * z4) - (x * y4 * z3);
	double D2 = (x1 * y * z3) + (x * y3 * z4) + (x3 * y4 * z1) + (x4 * y1 * z) - (z * y3 * x4) - (z1 * y * x3) - (y1 * x * z4) - (x1 * y4 * z3);
	double D3 = (x1 * y2 * z) + (x2 * y * z4) + (x * y4 * z1) + (x4 * y1 * z2) - (z2 * y * x4) - (z1 * y2 * x) - (y1 * x2 * z4) - (x1 * y4 * z);
	double D4 = (x1 * y2 * z3) + (x2 * y3 * z) + (x3 * y * z1) + (x * y1 * z2) - (z2 * y3 * x) - (z1 * y2 * x3) - (y1 * x2 * z) - (x1 * y * z3);

	
	if ((signbit(D0) == signbit(D1)) && (signbit(D0) == signbit(D2)) && (signbit(D0) == signbit(D3)) && (signbit(D0) == signbit(D4)))
		return true;

	else
		return false;
}


//Check if a point is on a boundary
bool Tetrahedron::operator>(const Point& point) const
{
	//Coordinates of th vertices of the tetrahedron
	double x1 = p1.getX(); double y1 = p1.getY(); double z1 = p1.getZ();
	double x2 = p2.getX(); double y2 = p2.getY(); double z2 = p2.getZ();
	double x3 = p3.getX(); double y3 = p3.getY(); double z3 = p3.getZ();
	double x4 = p4.getX(); double y4 = p4.getY(); double z4 = p4.getZ();

	double x = point.getX(); double y = point.getY(); double z = point.getZ();

	//Calculating determinants 
	double D0 = (x1 * y2 * z3) + (x2 * y3 * z4) + (x3 * y4 * z1) + (x4 * y1 * z2) - (z2 * y3 * x4) - (z1 * y2 * x3) - (y1 * x2 * z4) - (x1 * y4 * z3);
	double D1 = (x * y2 * z3) + (x2 * y3 * z4) + (x3 * y4 * z) + (x4 * y * z2) - (z2 * y3 * x4) - (z * y2 * x3) - (y * x2 * z4) - (x * y4 * z3);
	double D2 = (x1 * y * z3) + (x * y3 * z4) + (x3 * y4 * z1) + (x4 * y1 * z) - (z * y3 * x4) - (z1 * y * x3) - (y1 * x * z4) - (x1 * y4 * z3);
	double D3 = (x1 * y2 * z) + (x2 * y * z4) + (x * y4 * z1) + (x4 * y1 * z2) - (z2 * y * x4) - (z1 * y2 * x) - (y1 * x2 * z4) - (x1 * y4 * z);
	double D4 = (x1 * y2 * z3) + (x2 * y3 * z) + (x3 * y * z1) + (x * y1 * z2) - (z2 * y3 * x) - (z1 * y2 * x3) - (y1 * x2 * z) - (x1 * y * z3);

	if ((D1 == 0) || (D2 == 0) || (D3 == 0) || (D4 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Check if a point is on an edge
bool Tetrahedron::operator==(const Point& point) const
{
	//Coordinates of th vertices of the tetrahedron
	double x1 = p1.getX(); double y1 = p1.getY(); double z1 = p1.getZ();
	double x2 = p2.getX(); double y2 = p2.getY(); double z2 = p2.getZ();
	double x3 = p3.getX(); double y3 = p3.getY(); double z3 = p3.getZ();
	double x4 = p4.getX(); double y4 = p4.getY(); double z4 = p4.getZ();

	double x = point.getX(); double y = point.getY(); double z = point.getZ(); 

	double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
	double AP = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
	double PB = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) + (z2 - z) * (z2 - z));

	double AC = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1));
	double PC = sqrt((x3 - x) * (x3 - x) + (y3 - y) * (y3 - y) + (z3 - z) * (z3 - z));

	double AD = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));
	double PD = sqrt((x4 - x) * (x4 - x) + (y4 - y) * (y4 - y) + (z4 - z) * (z4 - z));

	double BC = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
	double BP = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2) + (z - z2) * (z - z2));

	double BD = sqrt((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) + (z4 - z2) * (z4 - z2));

	double CD = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3));
	double CP = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3) + (z - z3) * (z - z3));
	
	if ((AB == AP + PB) || (AC == AP + PC) || (AD == AP + PD) || (BC == BP + PC) || (BD == BP + PD) || (CD == CP + PC))
	{
		return true;
	}
	else
	{
		return false;
	}


}



bool Tetrahedron::validate()
{
	if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
	{
		throw EqualPointException();
	}
	return true;
}

std::ostream& Tetrahedron::ins(std::ostream& out)const {
	return out << "\nTetrahedron has the following vertices:\nVertice a: " 
	<< p1 << "\nVertice b: " << p2 << "\nVertice c: " << p3 << "\nVertice d: "<<p4 <<std::endl;
}

std::istream& Tetrahedron::ext(std::istream& in) {
	return in;
}

std::ostream& operator<<(std::ostream& out, const Tetrahedron& rhs)
{
	return rhs.ins(out);
}

std::istream& operator>>(std::istream& in, Tetrahedron& rhs)
{
	return rhs.ext(in);
}