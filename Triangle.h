#pragma once
#include"Point.h"
#include "Element.h"
#include<cstring>
#include <iostream>


class Triangle : public Point
{
protected:
	double a, b, c;
	//std::string kind;
	Point first, second, third;

public:
	Triangle(); // default ctor
	Triangle(const Triangle&);
	Triangle& operator=(const Triangle&);
	
	double getTriangleA();
	double getTriangleB();
	double getTriangleC();


	Point getFirst() const;
	Point getSecond()const;
	Point getThird() const;
	bool validate();

	//setters
	double setTriangleA(double aa);
	double setTriangleB(double bb);
	double setTriangleC(double cc);
	double TrianglePerimeter();
	double TriangleArea();
	void Angle(Triangle& tr);
	void strana(Triangle& tr);


	//methods

	Triangle makeTriangleFromPoints(Point& one, Point& two, Point& three);
	Point calculateTriangleCentroid(Triangle tr);
	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);

	bool operator <(Point& p);
	bool operator >(Point& p);
	//Triangle operator=(const Triangle&);
	~Triangle();
	bool operator ==(Point& p);
};
std::ostream& operator<<(std::ostream& , const Triangle&);
std::istream& operator>>(std::istream& , Triangle& );