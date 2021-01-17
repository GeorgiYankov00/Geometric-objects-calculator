#include "Triangle.h"
#include "Point.h"
#include "Element.h"
#include"EqualPointException.h"
#include<math.h>
#include <iomanip>
#include <iostream>
Triangle::Triangle():Point() {
	/*
	a = 0;
	b = 0;
	c = 0;
	*/
	first = Point(0, 0, 0);
	second = Point(0, 0, 0);
	third = Point(0, 0, 0);
}
Triangle::Triangle(const Triangle& rhs) {
	first = rhs.first;
	second = rhs.second;
	third = rhs.third;
}
Triangle Triangle::makeTriangleFromPoints(Point& one, Point& two, Point& three) {

	if (one == two || two == three || one == three)
	{
		this->validate();
	}
	first = one;
	second = two;
	third = three;
	a = sqrt((two.getX() - one.getX()) * (two.getX() - one.getX()) + ((two.getY() - one.getY()) * (two.getY() - one.getY())) + ((two.getZ() - one.getZ()) * (two.getZ() - one.getZ())));
	b = sqrt((three.getX() - two.getX()) * (three.getX() - two.getX()) + ((three.getY() - two.getY()) * (three.getY() - two.getY())) + ((three.getZ() - two.getZ()) * (three.getZ() - two.getZ())));
	c = sqrt((three.getX() - one.getX()) * (three.getX() - one.getX()) + ((three.getY() - one.getY()) * (three.getY() - one.getY())) + ((three.getZ() - one.getZ()) * (three.getZ() - one.getZ())));
	return *this;
}

bool Triangle::validate()
{
	if (first == second)
	{
		throw EqualPointException();
		
	}
	if (second == third)
	{
		throw EqualPointException();
		
	}
	if (first == third)
	{
		throw EqualPointException();
		
	}
	return true;
}



double Triangle::getTriangleA() {
	return a;
}

double Triangle::getTriangleB() {
	return b;
}

double Triangle::getTriangleC() {
	return c;
}




double Triangle::setTriangleA(double aa) {
	a = aa;
	return 0;
}

double Triangle::setTriangleB(double bb) {
	b = bb;
	return 0;
}

double Triangle::setTriangleC(double cc) {
	c = cc;
	return 0;
}

double Triangle::TrianglePerimeter() {
	return (this->getTriangleA() + this->getTriangleB() + this->getTriangleC()) / 2;

}

double Triangle::TriangleArea() {
	double perimeter = this->TrianglePerimeter();
	return sqrt(perimeter * ((perimeter - this->a ) * (perimeter -this->b ) * (perimeter - this->c)));

}
void Triangle::Angle(Triangle& tr) {
	Triangle& trang = *this;
	if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
	{
		std::cout << "right-angled" << std::endl;
	}
	else if (a + b < c || a + c < b || b + c < a)
	{
		std::cout << "obtuse" << std::endl;
	}
	else if (a + b > c || a + c > b || b + c > a)
	{
		std::cout << "acute" << std::endl;
	}

}

void Triangle::strana(Triangle& tr) {
	Triangle& trang = *this;
	if (a == b && b == c)
	{
		std::cout << "Ravnostranen" << std::endl;
	}
	else if (a == b || a == c || c == b)
	{
		std::cout << "Ravnobedren" << std::endl;
	}
	else
	{
		std::cout << "Raznostranen" << std::endl;
	}

}
Point Triangle::calculateTriangleCentroid(Triangle tr) {
	double X = (tr.first.getX() + tr.second.getX() + tr.third.getX()) / 3;
	double Y = (tr.first.getY() + tr.second.getY() + tr.third.getY()) / 3;
	double Z = (tr.first.getZ() + tr.second.getZ() + tr.third.getZ()) / 3;
	return Point(X, Y, Z);
}





Point Triangle::getFirst()const {
	return first;
}

Point Triangle::getSecond()const {
	return second;
}

Point Triangle::getThird()const {
	return third;
}

bool Triangle::operator <(Point& p) {
	double alpha = ((this->second.getY() - this->third.getY()) * (p.getX() - this->third.getX()) + (this->third.getX() - this->second.getX()) *
		(p.getY() - this->third.getY()) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY())));
	double beta = ((this->third.getY() - this->first.getY()) * (p.getX() - this->third.getX()) + (this->first.getX() - this->third.getX()) *
		(p.getY() - this->third.getY())) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY()));
	double gamma = 1.0 - alpha - beta;
	if ((alpha > 0) && (beta > 0) && (gamma > 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool Triangle::operator >(Point& p) {
	double alpha = ((this->second.getY() - this->third.getY()) * (p.getX() - this->third.getX()) + (this->third.getX() - this->second.getX()) *
		(p.getY() - this->third.getY()) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY())));
	double beta = ((this->third.getY() - this->first.getY()) * (p.getX() - this->third.getX()) + (this->first.getX() - this->third.getX()) *
		(p.getY() - this->third.getY())) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY()));
	double gamma = 1.0 - alpha - beta;
	if ((alpha > 0) && (beta > 0) && (gamma > 0)) {
		return false;
	}
	else {
		return true;
	}

}

bool Triangle::operator ==(Point& p) {
	double alpha = ((this->second.getY() - this->third.getY()) * (p.getX() - this->third.getX()) + (this->third.getX() - this->second.getX()) *
		(p.getY() - this->third.getY()) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY())));
	double beta = ((this->third.getY() - this->first.getY()) * (p.getX() - this->third.getX()) + (this->first.getX() - this->third.getX()) *
		(p.getY() - this->third.getY())) / ((this->second.getY() - this->third.getY()) * (this->first.getX() - this->third.getX()) +
			(this->third.getX() - this->second.getX()) * (this->first.getY() - this->third.getY()));
	double gamma = 1.0 - alpha - beta;
	if ((alpha == 0) && (beta == 0) && (gamma == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//	double a, b, c, perimeter, area, centroid;

Triangle& Triangle::operator=(const Triangle & rhs){
	if (this != &rhs) {
		first = rhs.first;
		second = rhs.second;
		third = rhs.third;

	}
	return *this;
}


std::ostream& Triangle::ins(std::ostream& out)const {

	return out << "a= " <<std::setprecision(3) <<a << " ,b= " << b << " ,c= " <<c<< std::endl;
}
std::istream& Triangle::ext(std::istream& in) {
	Point::ext(in);

	return in;
	
}
std::ostream& operator<<(std::ostream& out, const Triangle& rhs) { return rhs.ins(out); }
std::istream& operator>>(std::istream& in, Triangle& rhs) { return rhs.ext(in); }
Triangle::~Triangle() {
}
