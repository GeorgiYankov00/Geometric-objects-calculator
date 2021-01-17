#pragma once
#include "Vector.h"
#define PI 3.14159265



class Line :public Vector
{
protected:
	double t;
	Vector vector;
	Point firstPoint, secondPoint;
public:
	//Default constructor
	Line();
	//Initializing a line with a Point and a Vector
	Line(const Point& first, const Vector& vec);
	//Initializing a line with two points
	Line(const Point& first,const Point& second);
	//Copy constructor
	Line(const Line& rhs);
	//Destructor
	~Line();

	// Get t
	double get_t() const;
	//Get firstPoint
	Point get_firstPoint() const;
	//Get secondPoint
	Point get_secondPoint() const;
	//Get vector
	Vector get_vector() const;

	// Set t
	void set_t(double);

	//Function to find the direction of the line
	Vector direction(); //Returns a vector parallel to the line

	//Function to find the normal vector to the line
	Vector normal_vector(); //Returns a vector perpendicular to the line

	//Function to find the angle between two lines
	double angle(const Line&); //Returns the angle in radians

	//Overloaded operator '=' 
	const Line& operator=(const Line&);

	//Overloaded operator '||' to find if a line is parallel to another
	bool operator||(const Line&);

	//Overloaded operator '==' to find if a line is coinside with another
	bool operator==(const Line&);

	//Overloaded operator '!=' to find if two lines are crossed
	bool operator !=(const Line&);

	//Overloaded operator '|' to find if a line is perpendicular to another line
	bool operator |(const Line&);

	//Overrode i/o flows
	virtual std::ostream& ins(std::ostream&)const;
	virtual std::istream& ext(std::istream&);
};

//Overloaded operator '+' to check if a point lays on a line
bool operator +(const Line&, const Point&);

//Overloaded operator '&&' to find if two lines arre intersected
bool operator &&(const Line&, const Line&);


std::ostream& operator<<(std::ostream&, const Line&);
std::istream& operator>>(std::istream&, Line&);
