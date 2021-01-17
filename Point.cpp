#include<iostream>
#include "Point.h"
#include"Element.h"
#include"Triangle.h"
// Constructor
Point::Point() : x(0), y(0), z(0) {}

// Constructor
Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

// Copy Constructor
Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y), z(rhs.z) {}
Point& Point::operator=(const Point&rhs ){
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
}
	return *this;
}
std::ostream& Point::ins(std::ostream& out)const {
	out << "x= " << x << ", y= " << y << ", z= " << z;
	return out;

}
// Get X
double Point::getX() const
{
	return x;
}

// Get Y
double Point::getY() const
{
	return y;
}

// Get Z
double Point::getZ() const
{
	return z;
}

// Set X
void Point::setX(double x)
{
	this->x = x;
}

// Set Y
void Point::setY(double y)
{
	this->y = y;
}

// Set Z
void Point::setZ(double z)
{
	this->z = z;
}

// Compare two points
bool Point::operator==(Point& rhs)
{
	return (this->getX() == rhs.getX()) && (this->getY() == rhs.getY()) && (this->getZ() == rhs.getZ());
	// To be equal, the corresponding coordinates must be equal
}
bool Point::operator<(Triangle& tr) const {
	double alpha = ((tr.getSecond().getY() - tr.getThird().getY()) * (this->getX() - tr.getThird().getX()) + (tr.getThird().getX() - tr.getSecond().getX()) *
		(this->getY() - tr.getThird().getY()) / ((tr.getSecond().getY() - tr.getThird().getY()) * (tr.getFirst().getX() - tr.getThird().getX()) +
			(tr.getThird().getX() - tr.getSecond().getX()) * (tr.getFirst().getY() - tr.getThird().getY())));
	double beta = ((tr.getThird().getY() - tr.getFirst().getY()) * (this->getX() - tr.getThird().getX()) + (tr.getFirst().getX() - tr.getThird().getX()) *
		(this->getY() - tr.getThird().getY())) / ((tr.getSecond().getY() - tr.getThird().getY()) * (tr.getFirst().getX() - tr.getThird().getX()) +
			(tr.getThird().getX() - tr.getSecond().getX()) * (tr.getFirst().getY() - tr.getThird().getY()));
	double gamma = 1.0 - alpha - beta;

	return ((alpha > 0) && (beta > 0) && (gamma > 0));
}

bool Point::operator>(Triangle& tr) const {
	double alpha = ((tr.getSecond().getY() - tr.getThird().getY()) * (this->getX() - tr.getThird().getX()) + (tr.getThird().getX() - tr.getSecond().getX()) *
		(this->getY() - tr.getThird().getY()) / ((tr.getSecond().getY() - tr.getThird().getY()) * (tr.getFirst().getX() - tr.getThird().getX()) +
			(tr.getThird().getX() - tr.getSecond().getX()) * (tr.getFirst().getY() - tr.getThird().getY())));
	double beta = ((tr.getThird().getY() - tr.getFirst().getY()) * (this->getX() - tr.getThird().getX()) + (tr.getFirst().getX() - tr.getThird().getX()) *
		(this->getY() - tr.getThird().getY())) / ((tr.getSecond().getY() - tr.getThird().getY()) * (tr.getFirst().getX() - tr.getThird().getX()) +
			(tr.getThird().getX() - tr.getSecond().getX()) * (tr.getFirst().getY() - tr.getThird().getY()));
	double gamma = 1.0 - alpha - beta;

	return ((alpha > 0) && (beta > 0) && (gamma > 0));
}
std::istream& Point::ext(std::istream& in) {
	//Element::ext();
	std::cout << "\nEnter coordinates: \n";
	std::cout << "x :";
	in >> x;
	std::cout << "y :";
	in >> y;
	std::cout << "z :";
	in >> z;
	in.ignore();
	return in;
}
std::ostream& operator<<(std::ostream& out, const Point&rhs){return rhs.ins(out); }
std::istream& operator>>(std::istream& in, Point& rhs){ return rhs.ext(in); }