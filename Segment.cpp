#include "Segment.h"
#include "Point.h"
#include "vector.h"
#include<iostream>

Segment::Segment() : pA(), pB() {};

Segment::Segment(const Point& pA, const Vector& vec) : Line(pA, vec), pA(pA) {
	double dx = vec.getX();
	double dy = vec.getY();
	double dz = vec.getZ();

	pB = Point(pA.getX() + dx, pA.getY() + dy, pA.getZ() + dz);
};

Segment::Segment(const Point& pA, const Point& pB) : Line(pA, pB), pA(pA), pB(pB) {};

//dobawqm kym wsqka kordinata na tochka dyhvinata na proekciqta po syotwetnata koordinata
//da se definira po tochka i vector
//da se definira po tochka i tochka se nasledqwa ot Line


//tova e za dalvinata - tochka 1
//izpolzwa se ot vector formulata 
//d zashtoto e razlika na syotwetnata koordinata ot nachalnata i krainata tochka dx=ax-bx
double Segment::getLength() {
	double dx = pB.getX() - pA.getX();
	double dy = pB.getY() - pA.getY();
	double dz = pB.getZ() - pA.getZ();
	Vector vec(dx, dy, dz);
	return vec.vector_length();
};

//towa e za wtorata tochka
Point Segment::getMidpoint() {
	double x = (pA.getX() + pB.getX()) / 2;
	double y = (pA.getY() + pB.getY()) / 2;
	double z = (pA.getZ() + pB.getZ()) / 2;
	return Point(x, y, z);
};


//prawim now wector s edna ot tochkite ot nashiq segment, wtorata e tazi, koqto trqbwa da proverim dali levi
//smqtame razstoqnieto ot C do A i ot C do B, kato prowerqwame dali c levi, ako AC + BC = AB, znaci tq levi 
bool Segment::operator ==(const Point& pC) {
	Segment AC(pA, pC);
	Segment BC(pB, pC);

	return getLength() == AC.getLength() + BC.getLength();
}

std::istream& Segment::ext(std::istream& in) {
	cout << "Enter start point: ";
	in >> pA;
	cout << "Enter end point: ";
	in >> pB;
	in.ignore();
	return in;
}

std::ostream& Segment::ins(std::ostream& out)const {
	out << "Start point: " << pA << endl;
	out << "End point: " << pB << endl;
	return out;
}
std::ostream& operator<<(std::ostream& out, const Segment& rhs) { return rhs.ins(out); }
std::istream& operator>>(std::istream& in, Segment& rhs) { return rhs.ext(in); }

