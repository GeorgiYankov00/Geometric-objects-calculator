#include "Vector.h"
#include "Point.h"
#include "Element.h"
#include <iostream>
Vector::Vector(double x, double y, double z) :Point(x,y,z) {};
Vector::Vector() :Point(0, 0, 0) {};
Vector::Vector(const Vector& rhs) :Point() { }
Vector::Vector(const Point& A,const Point& B):Vector(B.getX() - A.getX(), B.getY() - A.getY(), B.getZ() - A.getZ()){}
Vector& Vector:: operator=(const Vector& rhs) {
	if (this != &rhs) {	
		Point::operator=(rhs);
	}
	return *this;
}
std::ostream& Vector::ins(std::ostream& out)const {
	//Point::ins(out);
	return out << "(" << getX() << ", " << getY() << ", " << getZ() << ")";
}
//zadacha 2
double Vector::vector_length(){

	return sqrt(pow(this->getX(),2)+pow(this->getY(),2)+pow(this->getZ(),2));
}
Vector Vector::vector_direction(){
	//exception
	double i, j, k;
	i = this->getX() / vector_length();
	j = this->getY() / vector_length();
	k = this->getZ() / vector_length();
	return Vector(i, j, k);
}
bool Vector::vector_null() {
	if (this->getX() == this->getY() && this->getY() == this->getZ() && this->getZ() == 0) return true;
	return false;
}
bool Vector::vector_parallelism(Vector& v) {
	//exception
	if (this->getX() / v.getX() == this->getY() / v.getY() && this->getY() / v.getY() == this->getZ() / v.getZ()) {
		return true;
	}
	else {
		return false;
	}
	
}
bool Vector::vector_perpendicularity(Vector& v) {
	//exception
	if (this->getX() * v.getX() + this->getY() * v.getY() + this->getZ() * v.getZ() == 0) {
		return true;
	}
	else {
		return false;
	}
	
}
//zadacha 3
Vector Vector::operator +(const Vector& r){
	return Vector(r.getX() + getX(), r.getY() + getY(), r.getZ() + getZ());
}
Vector Vector::operator -(const Vector& r) {
	//a − v = (x, y, z) − (v1, v2, v3) = (x − v1, y − v2, z − v3);
	return Vector(this->getX() - r.getX(), this->getY() - r.getY(), this->getZ() - r.getZ());
}
double Vector::operator *(const Vector& r) {
	return r.getX() * getX() + r.getY() * getY() + r.getZ() * getZ();
}
Vector Vector::operator ^(const Vector& r) {
	//(y.v3 − z.v2, −x.v3 + z.v1, x.v2 − y.v1).
	return Vector(this->getY() * r.getZ() - this->getZ() * r.getY(), this->getZ() * r.getX() - this->getX() * r.getZ(), this->getX() * r.getY() - this->getY() * r.getX());
}
double Vector::operator()(const Vector& v2, const Vector& v3) {
	//u e this

	return (this->getY() * v2.getZ() - v2.getY() * this->getZ()) * v3.getX()
		- (this->getX() * v2.getZ() - v2.getX() * this->getZ()) * v3.getY()
		+ (this->getX() * v2.getY() - this->getY() * v2.getX()) * v3.getZ();
}
Vector vector_multipy(double& num, Vector& r) {
	return Vector(r.getX() * num, r.getY() * num, r.getZ() * num);
}
Vector::~Vector(){}


std::istream& Vector::ext(std::istream& in){
	
	 Point::ext(in);
	 return in;
}
std::ostream& operator<<(std::ostream& out, const Vector&rhs) { return rhs.ins(out); }
std::istream& operator>>(std::istream& in, Vector& rhs) { return rhs.ext(in); }

