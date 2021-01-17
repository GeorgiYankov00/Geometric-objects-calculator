#pragma once
#ifndef Vector_h
#define Vector_h
#include <iostream>
#include <cstring>
#include "Point.h"
#include "Element.h"
class Vector: public Point {
public:
	Vector();
	Vector(double, double, double);
	Vector(const Vector&);
	Vector(const Point&,const Point&);
	Vector& operator=(const Vector&);
	//zadacha 2
	double vector_length();
	Vector vector_direction();
	bool vector_null();
	virtual bool vector_parallelism(Vector&);
	bool vector_perpendicularity(Vector&);
	//zadacha 3
	Vector operator +(const Vector&);
	Vector operator -(const Vector&);
	double operator *(const Vector&);
	double operator()(const Vector& v2, const Vector& v3);
	Vector operator ^(const Vector&);
	~Vector();
	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};
Vector vector_multipy(double&,Vector&);
std::ostream& operator<<(std::ostream&, const Vector&);
std::istream& operator>>(std::istream& , Vector& );

#endif
