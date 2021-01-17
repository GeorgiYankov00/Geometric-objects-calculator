#include "Line.h"
#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

//Default constructor
Line::Line() :Vector()
{
	t = 0.;
	firstPoint = Point(0, 0, 0);
	secondPoint = Point(0, 0, 0);
	vector = Vector(0, 0, 0);
}


// Get t
double Line::get_t() const
{
	return t;
}

// Set t
void Line::set_t(double t)
{
	this->t = t;
}

//Get vector
Vector Line::get_vector() const
{
	return Vector(vector.getX(), vector.getY(), vector.getZ());
}

//Get firstPoint
Point Line::get_firstPoint() const
{
	return firstPoint;
}
//Get secondPoint
Point Line::get_secondPoint() const
{
	return secondPoint;
}


//Constructor to create a line form two points
Line::Line(const Point& first,const Point& second)
{
	firstPoint = first;
	secondPoint = second;
	vector = Vector(first, second);

	std::cout << "\nPlease enter value for t for the line equation: ";
	std::cin >> t;

	x = firstPoint.getX() + t * (vector.getX());
	y = firstPoint.getY() + t * (vector.getY());
	z = firstPoint.getZ() + t * (vector.getZ());
}

//Constructor to create a line from a point and a vector
Line::Line(const Point& first,const Vector& vec)
{
	vector = vec;
	firstPoint = Point(first.getX(), first.getY(), first.getZ());

	std::cout << "\nPlease enter value for t for the line equation: ";
	std::cin >> t;

	x = firstPoint.getX() + t * (vector.getX());
	y = firstPoint.getY() + t * (vector.getY());
	z = firstPoint.getZ() + t * (vector.getZ());
}

//Copy constructor
Line::Line(const Line& rhs) :Vector(rhs)
{
	vector = rhs.vector;
	firstPoint = rhs.firstPoint;
	secondPoint = rhs.secondPoint;
	t = rhs.t;
}

//Function to find the direction of the line
Vector Line::direction() //Returns a vector parallel to the line
{
	return this->get_vector();
}

//Function to find the normal vector to the line
Vector Line::normal_vector()//Returns a vector perpendicular to the line
{
	Vector dir_vec_1 = this->get_vector(); double l = dir_vec_1.getX(); double m = dir_vec_1.getY(); double n = dir_vec_1.getZ();
	Point first = this->get_firstPoint(); double x1 = first.getX(); double y1 = first.getY(); double z1 = first.getZ();
	
	double k = -(l * x1 + m * y1 + n * z1) / (pow(l, 2) + pow(m, 2) + pow(n, 2));

	double x_normal_vector = (l * k) + x1;
	double y_normal_vector = (m * k) + y1;
	double z_normal_vector = (n * k) + z1;
	
	return Vector (x_normal_vector, y_normal_vector, z_normal_vector);
}


//Function to find the angle between two lines
double Line::angle(const Line& secondLine) //Returns the angle in radians
{
	Vector dir_vec_1 = this->get_vector(); double x1 = dir_vec_1.getX(); double y1 = dir_vec_1.getY(); double z1 = dir_vec_1.getZ();
	Vector dir_vec_2 = secondLine.get_vector(); double x2 = dir_vec_2.getX(); double y2 = dir_vec_2.getY(); double z2 = dir_vec_2.getZ();
	
	double cos_of_angle = ((x1 * x2) + (y1 * y2) + (z1 * z2)) / (sqrt(pow(x1, 2) + pow(y1, 2) + pow(z1, 2)) * sqrt(pow(x2, 2) + pow(y2, 2) + pow(z2, 2)));

	double angle_in_radians = acos(cos_of_angle) * 180.0 / PI;

	return angle_in_radians;
}

//Overloaded operator '='
const Line& Line::operator=(const Line& rhs)
{
	if (this != &rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		this->t = rhs.t;
		this->firstPoint = rhs.firstPoint;
		this->secondPoint = rhs.secondPoint;
		this->vector = rhs.vector;
	}

	return *this;
}

//Overloaded operator '+' to check if a point lays on a line
bool operator +(const Line& line, const Point& point)
{
	//Трябва да се извлекат стойностите на x, y, z за двете точки, от които линията ще се образува
	//Както и на точката, която ще проверяваме дали лежи на линията
	//Координати на точки: line.pnt1: x1,y1,z1; line.pt2: x2,y2,z2; point: x,y,z
	//Проверката става е изпълнено равенството: (AB == AP + PB)
	//Където A и B са краищата на правата и P е точката, която проверяваме

	double x = point.getX(); double y = point.getY(); double z = point.getZ();
	Point first = line.get_firstPoint(); double x1 = first.getX(); double y1 = first.getY(); double z1 = first.getZ();
	Point second = line.get_secondPoint(); double x2 = second.getX(); double y2 = second.getY(); double z2 = second.getZ();

	double AB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
	double AP = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1) + (z - z1) * (z - z1));
	double PB = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) + (z2 - z) * (z2 - z));

	if (AB == AP + PB)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//Destructor
Line::~Line()
{
}

///Overloaded operator '||' to find if a line is parallel to another
bool Line::operator|| (const Line& secondLine)
{

	Vector dir_vec_1 = this->get_vector(); double x1 = dir_vec_1.getX(); double y1 = dir_vec_1.getY(); double z1 = dir_vec_1.getZ();
	Vector dir_vec_2 = secondLine.get_vector(); double x2 = dir_vec_2.getX(); double y2 = dir_vec_2.getY(); double z2 = dir_vec_2.getZ();

	if ((x1 / x2) == (y1 / y2) == (z1 / z2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloaded operator '==' to find if a line is coinside with another
bool Line::operator==(const Line& secondLine)
{
	//If they are parallel and they intersect at a point, then they coinside

	Vector dir_vec_1 = this->get_vector(); double dir_vec_x1 = dir_vec_1.getX(); double dir_vec_y1 = dir_vec_1.getY(); double dir_vec_z1 = dir_vec_1.getZ();
	Vector dir_vec_2 = secondLine.get_vector(); double dir_vec_x2 = dir_vec_2.getX(); double dir_vec_y2 = dir_vec_2.getY(); double dir_vec_z2 = dir_vec_2.getZ();

	double x1 = this->getX(); double y1 = this->getY(); double z1 = this->getZ();
	double x2 = secondLine.getX(); double y2 = secondLine.getY(); double z2 = secondLine.getZ();

	if ((dir_vec_x1 / dir_vec_x1) == (dir_vec_y1 / dir_vec_y2) == (dir_vec_z1 / z2) && ((x1 == x2) || (y1 == y2) || (z1 == z2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Overloaded operator '&&' to find if two lines are intersected
bool operator &&(const Line& firstLine, const Line& secondLine)
{
	double x1 = firstLine.getX(); double y1 = firstLine.getY(); double z1 = firstLine.getZ();
	double x2 = secondLine.getX(); double y2 = secondLine.getY(); double z2 = secondLine.getZ();

	if ((x1 == x2) || (y1 == y2) || (z1 == z2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloaded operator '!=' to find if two lines are crossed
bool Line::operator !=(const Line& secondLine)
{
	Point first = this->get_firstPoint(); double x1 = first.getX(); double y1 = first.getY(); double z1 = first.getZ();
	Point second = secondLine.get_secondPoint(); double x2 = second.getX(); double y2 = second.getY(); double z2 = second.getZ();

	Vector dir_vec_1 = this->get_vector(); double dir_vec_x1 = dir_vec_1.getX(); double dir_vec_y1 = dir_vec_1.getY(); double dir_vec_z1 = dir_vec_1.getZ();
	Vector dir_vec_2 = secondLine.get_vector(); double dir_vec_x2 = dir_vec_2.getX(); double dir_vec_y2 = dir_vec_2.getY(); double dir_vec_z2 = dir_vec_2.getZ();

	//The determinant of the mixed product (the vector between firstPoint and secondPoint x direction vector of firstLine x direction vector of secondLine)
	double determinant = (x2 - x1) * ((dir_vec_y1 * dir_vec_z2) - (dir_vec_z1 * dir_vec_y2)) - (y2 - y1) * ((dir_vec_x1 * dir_vec_z2) - (dir_vec_z1 * dir_vec_x2)) + (z2 - z1) * ((dir_vec_x1 * dir_vec_y2) - (dir_vec_y1 * dir_vec_x2));

	if (determinant != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Overloaded operator '|' to find if a line is perpendicular to another line
bool Line::operator |(const Line& secondLine)
{
	//For the lines to be perpendicular the dot equation of the two lines must be equal to 0
	Vector dir_vec_1 = this->get_vector(); double x1 = dir_vec_1.getX(); double y1 = dir_vec_1.getY(); double z1 = dir_vec_1.getZ();
	Vector dir_vec_2 = secondLine.get_vector(); double x2 = dir_vec_2.getX(); double y2 = dir_vec_2.getY(); double z2 = dir_vec_2.getZ();

	double dot_equation = (x1 * x2) + (y1 * y2) + (z1 * z2);

	if (dot_equation == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::ostream& Line::ins(std::ostream& out)const
{
	return out << "\nLine has the following coordinates for t = " << get_t() << ":\nx= " << getX() << "\ny= " << getY() << "\nz= " << getZ() << std::endl << std::endl;
}

std::istream& Line::ext(std::istream& in)
{

	std::cout << "\nPlease enter value for t for the line equation: ";
	in >> t;
	std::cout << "\nPlease enter coordinates for the first Point: ";
	in >> firstPoint;
	std::cout << "\nPlease enter coordinates for the second Point: ";
	in >> secondPoint;
	std::cout << "\nPlease enter coordinates for the vector: ";
	in >> vector;
	in.ignore();
	return in;
}
std::ostream& operator<<(std::ostream& out, const Line& rhs) { return rhs.ins(out); }
std::istream& operator>>(std::istream& in, Line& rhs) { return rhs.ext(in); }