#pragma once
#ifndef Tetrahedron_h
#define Tetrahedron_h
#include "Point.h"
#include "Triangle.h"
#include "Element.h"
#include "Line.h"
#include "EqualPointException.h"
#include"Triangle.h"
#include <algorithm>
#include <iostream>

class Tetrahedron : public Triangle {
public:
	// Constructors
	Tetrahedron();
	Tetrahedron(Point&, Point&, Point&, Point&);
	Tetrahedron(const Tetrahedron&);

	// Destructor
	~Tetrahedron();

	bool isRegular();
	float getSurface();
	float getVolume(Point&, Point&, Point&, Point&);

	const Tetrahedron& operator=(const Tetrahedron& rhs);
	bool operator<(const Point&) const;
	bool operator>(const Point&) const;
	bool operator==(const Point&) const;

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);

private:
	Point p1, p2, p3, p4;

	bool validate();
};

std::ostream& operator<<(std::ostream&, const Tetrahedron&);
std::istream& operator>>(std::istream&, Tetrahedron&);

#endif