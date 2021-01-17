#pragma once
#include "Line.h"
using namespace std;

class Point;

class  Segment :public Line {
protected:
	Point pA;
	Point pB;

public:
	Segment();
	Segment(const Point& pA, const Vector& vec);
	Segment(const Point& pA, const Point& pB);
	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
	double getLength();
	Point getMidpoint();
	bool operator ==(const Point&);
};
std::ostream& operator<<(std::ostream&, const Segment&);
std::istream& operator>>(std::istream&, Segment&);