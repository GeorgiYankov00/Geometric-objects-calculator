#include "Tetrahedron.h"
#include "Segment.h"
#include "Line.h"
#include "Vector.h"
#include "Triangle.h"
#include "Element.h"
#include "Point.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	unsigned obj_choice, fun_choice, fun_choice2, fun_choice3;
	//array for answers (y / n)
	char rep[1];
	rep[0] = 'y';
	Vector v, v1, v2;
	Point p, p1, p2, p3;
	Triangle t;
	int input_type;
	Tetrahedron* pt = new Tetrahedron;

	Line* pt_line = new Line;
	Line* pt_line2 = new Line;

	Segment* pt_seg = new Segment;

	cout << "Enter which input type you preffer- 1 for Console, 2 for File:\n";
	cin >> input_type;

	if (input_type == 1) {
		do {
			cout << "Select the geometry object you would like to see operations with:\n";
			cout << "1.Point\n2.Vector\n3.Line\n4.Segment\n5.Triangle\n6.Tetrahedron";
			cin >> obj_choice;
			switch (obj_choice) {
			case 1: {
				//Point
				cout << "\nPlease enter values for x,y,z: ";
				cin >> p;
				do {
					cout << "Please choice an option for a specific operation you would like to see with this point:\n"
						<< "1.Check if two points coinside.\n";
					cin >> fun_choice;
					switch (fun_choice) {
						//Check if two points coinside
					case 1:
						cout << "Please enter values for second Point:";
						cin >> p1;
						if (p == p1)
							cout << "The two points coinside.\n";
						else
							cout << "The two points don't coinside.\n";

						cout << "\nDo you want to see another operation with this point ? y / n\n";
						cin >> rep[0];
						break;
					}
				} while (rep[0] == 'y');
				cout << "Do you want to see operations with another object?y / n\n";
				cin >> rep[0];
				break;
			}
			case 2:
				//Vector:
				cout << "Please enter values for x,y,z: ";
				cin >> v;
				do {
					cout << "Please choice an option for a specific operation you would like to see with this vector:\n"
						<< "1.Check if Vector is null.\n2.Check Vector lenght.\n3.Check Vector direction.\n4.Multiply the vector with a number\n"
						<< "5.Check if vectors are perpendicular.\n6.Check if vectors are parallel.\n7.Operation + with vectors\n8.Operation - with vectors\n"
						<< "9.Multiplication of vectors.\n10.Vector multiplication with operation ^\n11.Mixed product vectors.\n";
					cin >> fun_choice;

					//vector functions
					switch (fun_choice) {
						//Check if Vector is null
					case 1:
						if (v.vector_null())cout << "Vector" << v << " is null. Do you want to see another operation with this vector? y/n\n";
						else cout << "Vector" << v << " is not null. Do you want to see another operation with this vector? y/n\n";
						cin >> rep[0];
						break;
						//Check Vector length
					case 2:
						cout << "The length of Vector " << v << " is " << v.vector_length() << ". Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						//Check Vector direction
						break;
					case 3:
						cout << "The direction of vector " << v << " is a new vector with the following cordinates: " << v.vector_direction() << ". Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Multiply the vector with a number
					case 4:
						double num;
						cout << "Enter values for num:";
						cin >> num;
						cout << "The result after multiplaying Vector " << v << " with " << num << " is a new vector with the following cordinates: " << vector_multipy(num, v) << ". Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Check if vectors are perpendicular
					case 5:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						if (v.vector_perpendicularity(v1))cout << "Vector " << v << " and Vector " << v1 << " Vectors are perpendicular. Do you want to see another operation with this vector ? y / n\n";
						else cout << "Vector " << v << " and Vector " << v1 << " Vectors are not perpendicular. Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Check if vectors are parallel
					case 6:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						if (v.vector_parallelism(v1))cout << "Vector " << v << " and Vector " << v1 << " Vectors are parralel. Do you want to see another operation with this vector ? y / n\n";
						else cout << "Vector " << v << " and Vector " << v1 << " Vectors are not parralel. Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Operation + with vectors
					case 7:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						cout << "The result after addition between Vector " << v << " and Vector " <<
							v1 << " is a new vector " << v + v1 << ". Do you want to see another operation with this vector ? y / n\n";
						v + v1;
						cin >> rep[0];
						break;
						//Operation - with vectors
					case 8:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						cout << "The result after substraction between Vector " << v << " and Vector " <<
							v1 << " is a new vector " << v - v1 << ". Do you want to see another operation with this vector ? y / n\n";

						cin >> rep[0];
						break;
						//Multiplication of vectors
					case 9:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						cout << "The result after multiplication between Vector " << v << " and Vector " << v1 <<
							" is a real number with value " << v * v1 << ". Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Vector multiplication with operation ^
					case 10:
						cout << "Please enter values for second Vector:\n";
						cin >> v1;
						v2 = v ^ v1;
						cout << "The result after Vector multiplication, operation ^, between Vector " << v << " and Vector " <<
							v1 << " is a new vector  " << v2 << ". Do you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
						//Mixed product vectors
					case 11:
						cout << "Enter values for the second and the third vector:\n";
						cin >> v1 >> v2;
						cout << "The result after Scalar triple product between: Vector " << v << " , Vector " << v1 << " ,Vector " << v2 << "is a real number with value " << v(v1, v2);
						cout << "\nDo you want to see another operation with this vector ? y / n\n";
						cin >> rep[0];
						break;
					}
				} while (rep[0] == 'y');
				cout << "Do you want to see operations with another object?y / n\n";
				cin >> rep[0];
				break;

				//Line
			case 3: {
				cout << "How would you like to initialize the line:\n"
					<< "1.By using two points.\n"
					<< "2.By using a point and a vector.\n";
				cin >> fun_choice;
				if (fun_choice == 1) {
					cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
					cin >> p >> p1;
					Line l(p, p1);
					pt_line = &l;

					cout << *pt_line;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this line:\n"
							<< "1.Find the direction of the line (returns the direction vector of the line).\n"
							<< "2.Find the normal vector of the line.\n"
							<< "3.Find the angle between two lines (in radians).\n"
							<< "4.Check if a point is on the line\n"
							<< "5.Check if a line is parallel to the first line.\n"
							<< "6.Check if a line is coinside with the first line.\n"
							<< "7.Check if two lines are intersected\n"
							<< "8.Check if two lines are crossed\n"
							<< "9.Check if a line is perpendicular to the first line.\n\n";
						cin >> fun_choice2;

						//line functions
						switch (fun_choice2) {
						case 1: {
							cout << "The direction of the line is a directional vector: " << pt_line->direction() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break; }
						case 2: {
							cout << "The normal vector of the line is vector: " << pt_line->normal_vector() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break;
						}
						case 4: {
							cout << "Please enter coordinates for the point: ";
							cin >> p2;
							if (*pt_line + p2 == true)
								cout << "The point is on the line.\n\n";
							else
								cout << "The point is not on the line.\n\n";

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break;
						}
						}
						if (fun_choice2 == 3) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 5) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 6) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 7) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}


							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 8) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 9) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

					} while (rep[0] == 'y');

				}
				else if (fun_choice == 2) {
					cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
					cin >> p >> v;
					Line l(p, v);
					pt_line = &l;

					cout << *pt_line;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this line:\n"
							<< "1.Find the direction of the line (returns the direction vector of the line).\n"
							<< "2.Find the normal vector of the line.\n"
							<< "3.Find the angle between two lines (in radians).\n"
							<< "4.Check if a point is on the line\n"
							<< "5.Check if a line is parallel to the first line.\n"
							<< "6.Check if a line is coinside with the first line.\n"
							<< "7.Check if two lines are intersected\n"
							<< "8.Check if two lines are crossed\n"
							<< "9.Check if a line is perpendicular to the first line.\n\n";
						cin >> fun_choice2;

						//line functions
						switch (fun_choice2) {
						case 1: {
							cout << "The direction of the line is a directional vector: " << pt_line->direction() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break; }
						case 2: {
							cout << "The normal vector of the line is vector: " << pt_line->normal_vector() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break;
						}
						case 4: {
							cout << "Please enter coordinates for the point: ";
							cin >> p2;
							if (*pt_line + p2 == true)
								cout << "The point is on the line.\n\n";
							else
								cout << "The point is not on the line.\n\n";

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
							break;
						}
						}
						if (fun_choice2 == 3) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 5) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 6) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 7) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}


							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 8) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

						if (fun_choice2 == 9) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							cin >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								cin >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								cin >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							cin >> rep[0];
						}

					} while (rep[0] == 'y');
				}

				cout << "Do you want to see operations with another object?y / n\n";
				cin >> rep[0];
				break; }

				  //Segment
			case 4:

				cout << "How would you like to initialize the segment:\n"
					<< "1.By using two points.\n"
					<< "2.By using a point and a vector.\n";
				cin >> fun_choice;
				if (fun_choice == 1) {
					cout << "Enter 3 coordinates for two separate points in order to create the Segment:\n";
					cin >> p >> p1;
					Segment s(p, p1);
					pt_seg = &s;

					cout << *pt_seg;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this Segment:\n"
							<< "1.Find the lenght of the segment.\n"
							<< "2.Find the middle of the segment.\n"
							<< "3.Check if a point is on the segment\n\n";
						cin >> fun_choice2;
						switch (fun_choice2) {
						case 1: {
							cout << "The lenght of the segment is: " << pt_seg->getLength() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}

						case 2: {
							cout << "The middle of the segment is a point with coordinates: " << pt_seg->getMidpoint() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}

						case 3: {
							cout << "Please enter coordinates for the point: ";
							cin >> p2;
							if ((*pt_seg == p2) == true)
								cout << "The point is on the segment.\n\n";
							else
								cout << "The point is not on the segment.\n\n";

							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}
						}
					} while (rep[0] == 'y');
				}
				else if (fun_choice == 2) {
					cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Segment:\n";
					cin >> p >> v;
					Segment s(p, v);
					pt_seg = &s;

					cout << *pt_seg;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this Segment:\n"
							<< "1.Find the lenght of the segment.\n"
							<< "2.Find the middle of the segment.\n"
							<< "3.Check if a point is on the segment\n\n";
						cin >> fun_choice2;
						switch (fun_choice2) {
						case 1: {
							cout << "The lenght of the segment is: " << pt_seg->getLength() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}

						case 2: {
							cout << "The middle of the segment is a point with coordinates: " << pt_seg->getMidpoint() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}

						case 3: {
							cout << "Please enter coordinates for the point: ";
							cin >> p2;
							if ((*pt_seg == p2) == true)
								cout << "The point is on the segment.\n\n";
							else
								cout << "The point is not on the segment.\n\n";

							cout << "Do you want to see another operation with this segment? y / n\n";
							cin >> rep[0];
							break;
						}
						}
					} while (rep[0] == 'y');
				}

				cout << "Do you want to see operations with another object?y / n\n";
				cin >> rep[0];
				break;

				//Triangle
			case 5: cout << "Enter 3 cordinates for 3 separete points in order to create a Triangle:\n ";
				cin >> p >> p1 >> p2;
				t.makeTriangleFromPoints(p, p1, p2);
				do {
					cout << "Please choice an option for a specific operation you would like to see with this Triangle:\n"
						<< "1.Specify the triangle type.\n2.Calculate the triangle area.\n3.Calculate the triangle perimeter.\n4.Calculate the Point that is Centroid for the triangle.\n"
						<< "5.Check if a Point lies in the same plain and is within the Triangle.\n6.Check if a Point lies in the same plain and is not within the Triangle.\n7.Check if a Point lies on one of the Triangle's sides.\n";
					cin >> fun_choice;
					switch (fun_choice) {
						//Specify the triangle type
					case 1:
						//t.TriangleKind(t);
						t.Angle(t);
						t.strana(t);
						cout << "Do you want to see other operations with this Triangle?y / n\n";
						cin >> rep[0];
						break;
						//triangle area
					case 2:
						cout << "The area of Triangle with sides:" << t << " is " << t.TriangleArea();
						cout << ". Do you want to see other operations with this Triangle?y / n\n";
						cin >> rep[0];
						break;
						//triangle perimeter
					case 3:
						cout << "The perimeter of Triangle with sides:" << t << " is " << t.TrianglePerimeter();
						cout << "Do you want to see other operations with is Triangle?y / n\n";
						cin >> rep[0];
						break;
						//Calculate the Point that is Centroid
					case 4:
						cout << "The centroid of Triangle with sides: " << t << " is a Point with the following cordinates: " << t.calculateTriangleCentroid(t);
						cout << ". Do you want to see operations with this Triangle?y / n\n";
						cin >> rep[0];
						break;
						//Check if a Point lies in the same plain and is in the Triangle <
					case 5:
						cout << "Enter values for Point in order to check if its in the same plain and lies within the Triangle:\n";
						cin >> p;
						if (t < p) {
							cout << "Point " << p << " lies on the same plain as the Triangle and it is within the Triangle. Do you want to see other operations with this Triangle ? y / n\n";
							cin >> rep[0];
						}
						else {
							cout << "Point " << p << " is not within the Triangle.Do you want to see other operations with this Triangle ? y / n\n";
							cin >> rep[0];
						}
						break;
						//Check if a Point lies in the same plain and is not in the Triangle >
					case 6:
						cout << "Enter values for Point in order to check if its in the same plain and lies outside the Triangle:\n";
						cin >> p;
						if (t > p) {
							cout << "Point " << p << " lies on the same plain as the Triangle and it is not outside the Triangle. Do you want to see other operations with this Triangle ? y / n\n";
							cin >> rep[0];
						}
						else {
							cout << "Point " << p << " is not outside the Triangle. Do you want to see other operations with this Triangle?y / n\n";
							cin >> rep[0];
						}
						break;
						//Check if a Point lies on of the Triangle's sides. ==
					case 7:
						cout << "Enter values for Point in order to check if it lies on one of the Triangle's sides:\n";
						cin >> p;
						if (t == p) {
							cout << "Point " << p << " lies on one of Triangle's sides. Do you want to other see operations with this Triangle?y / n\n";
							cin >> rep[0];
						}
						else {
							cout << "Point " << p << " does not lie on one of Triangle's sides. Do you want to see other operations with this Triangle?y / n\n";
							cin >> rep[0];
						}
						break;
					}
				} while (rep[0] == 'y');

			case 6:
				cout << "Enter 4 value of the four Tetrahedron coordinates " << endl;
				cin >> p >> p1 >> p2 >> p3;
				Tetrahedron t3(p, p1, p2, p3);
				pt = &t3;
				cout << *pt;

				do {
					cout << "Please choosee an option for a specific operation you would like to see with this Tetrahedron:\n"
						<< "1.Check if Tetrahedron is Regular.\n2.Check Tetrahedron Surface.\n3.Check Tetrahedron Volume.\n"
						<< "4.Check if a point is inside the tetrahedron.\n"
						<< "5.Check if a point is on a boundary of the tetrahedron.\n"
						<< "6.Check if a point is on an edge of the tetrahedron.\n" << endl;
					cin >> fun_choice;
					switch (fun_choice) {
					case 1:
						//Tetrahedron regularity
						if (t3.isRegular()) {
							cout << "The Tetrahedron is regular.Do you want to see other operations with this Tetrahedron?y / n\n";
							cin >> rep[0];
							break;
						}
						else {
							cout << "The Tetrahedron is not regular.Do you want to see other operations with this Tetrahedron?y / n\n";
							cin >> rep[0];
							break;
						}
						//surface
					case 2:
						cout << setprecision(5) << "The surface of the Tetrahedron is " << t3.getSurface() << " .\n";
						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						cin >> rep[0];
						break;
					case 3:
						cout << "The volume of the Tetrahedron is " << setprecision(5) << t3.getVolume(p, p1, p2, p3) << " .\n";
						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						cin >> rep[0];
						break;

					case 4:
						cout << "Please enter coordinates for the point: ";
						cin >> p2;
						if ((t3 < p2) == true)
							cout << "The point is inside the tetrahedron.\n\n";
						else
							cout << "The point is not inside the tetrahedron.\n\n";

						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						cin >> rep[0];
						break;

					case 5:
						cout << "Please enter coordinates for the point: ";
						cin >> p2;
						if ((t3 > p2) == true)
							cout << "The point is on a boundary of the tetrahedron.\n\n";
						else
							cout << "The point is not on a boundary of the tetrahedron.\n\n";

						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						cin >> rep[0];
						break;

					case 6:
						cout << "Please enter coordinates for the point: ";
						cin >> p2;
						if ((t3 == p2) == true)
							cout << "The point is on an edge of the tetrahedron.\n\n";
						else
							cout << "The point is not on an edge of the tetrahedron.\n\n";

						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						cin >> rep[0];
						break;
					}
					

				} while (rep[0] == 'y');

				cout << "Do you want to see operations with another object?y / n\n";
				cin >> rep[0];
				break;
			}

		} while (rep[0] == 'y');
	}


	//FILe STREAM BELLOW!!!
	if (input_type == 2) {
		ifstream input_txt("Vector.txt",ios::in);
		if (input_txt.fail())cerr << "Vector.txt could not be opened!";



		do {
			cout << "Select the geometry object you would like to see operations with:\n";
			cout << "1.Point\n2.Vector\n3.Line\n4.Segment\n5.Triangle\n6.Tetrahedron";
			input_txt >> obj_choice;
			switch (obj_choice) {
			case 1: {
				//Point
				cout << "\nPlease enter values for x,y,z: ";
				input_txt >> p;
				do {
					cout << "Please choice an option for a specific operation you would like to see with this point:\n"
						<< "1.Check if two points coinside.\n";
					input_txt >> fun_choice;
					switch (fun_choice) {
						//Check if two points coinside
					case 1:
						cout << "Please enter values for second Point:";
						input_txt >> p1;
						if (p == p1)
							cout << "The two points coinside.\n";
						else
							cout << "The two points don't coinside.\n";

						cout << "\nDo you want to see another operation with this point ? y / n\n";
						input_txt >> rep[0];
						break;
					}
				} while (rep[0] == 'y');
				cout << "Do you want to see operations with another object?y / n\n";
				input_txt >> rep[0];
				break;
			}
			case 2:
				//Vector:
				cout << "Please enter values for x,y,z: ";
				input_txt >> v;
				do {
					cout << "Please choice an option for a specific operation you would like to see with this vector:\n"
						<< "1.Check if Vector is null.\n2.Check Vector lenght.\n3.Check Vector direction.\n4.Multiply the vector with a number\n"
						<< "5.Check if vectors are perpendicular.\n6.Check if vectors are parallel.\n7.Operation + with vectors\n8.Operation - with vectors\n"
						<< "9.Multiplication of vectors.\n10.Vector multiplication with operation ^\n11.Mixed product vectors.\n";
					input_txt >> fun_choice;

					//vector functions
					switch (fun_choice) {
						//Check if Vector is null
					case 1:
						if (v.vector_null())cout << "Vector" << v << " is null. Do you want to see another operation with this vector? y/n\n";
						else cout << "Vector" << v << " is not null. Do you want to see another operation with this vector? y/n\n";
						input_txt >> rep[0];
						break;
						//Check Vector length
					case 2:
						cout << "The length of Vector " << v << " is " << v.vector_length() << ". Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						//Check Vector direction
						break;
					case 3:
						cout << "The direction of vector " << v << " is a new vector with the following cordinates: " << v.vector_direction() << ". Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Multiply the vector with a number
					case 4:
						double num;
						cout << "Enter values for num:";
						input_txt >> num;
						cout << "The result after multiplaying Vector " << v << " with " << num << " is a new vector with the following cordinates: " << vector_multipy(num, v) << ". Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Check if vectors are perpendicular
					case 5:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						if (v.vector_perpendicularity(v1))cout << "Vector " << v << " and Vector " << v1 << " Vectors are perpendicular. Do you want to see another operation with this vector ? y / n\n";
						else cout << "Vector " << v << " and Vector " << v1 << " Vectors are not perpendicular. Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Check if vectors are parallel
					case 6:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						if (v.vector_parallelism(v1))cout << "Vector " << v << " and Vector " << v1 << " Vectors are parralel. Do you want to see another operation with this vector ? y / n\n";
						else cout << "Vector " << v << " and Vector " << v1 << " Vectors are not parralel. Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Operation + with vectors
					case 7:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						cout << "The result after addition between Vector " << v << " and Vector " <<
							v1 << " is a new vector " << v + v1 << ". Do you want to see another operation with this vector ? y / n\n";
						v + v1;
						input_txt >> rep[0];
						break;
						//Operation - with vectors
					case 8:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						cout << "The result after substraction between Vector " << v << " and Vector " <<
							v1 << " is a new vector " << v - v1 << ". Do you want to see another operation with this vector ? y / n\n";

						input_txt >> rep[0];
						break;
						//Multiplication of vectors
					case 9:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						cout << "The result after multiplication between Vector " << v << " and Vector " << v1 <<
							" is a real number with value " << v * v1 << ". Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Vector multiplication with operation ^
					case 10:
						cout << "Please enter values for second Vector:\n";
						input_txt >> v1;
						v2 = v ^ v1;
						cout << "The result after Vector multiplication, operation ^, between Vector " << v << " and Vector " <<
							v1 << " is a new vector  " << v2 << ". Do you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
						//Mixed product vectors
					case 11:
						cout << "Enter values for the second and the third vector:\n";
						input_txt >> v1 >> v2;
						cout << "The result after Scalar triple product between: Vector " << v << " , Vector " << v1 << " ,Vector " << v2 << "is a real number with value " << v(v1, v2);
						cout << "\nDo you want to see another operation with this vector ? y / n\n";
						input_txt >> rep[0];
						break;
					}
				} while (rep[0] == 'y');
				cout << "Do you want to see operations with another object?y / n\n";
				input_txt >> rep[0];
				break;

				//Line
			case 3: {
				cout << "How would you like to initialize the line:\n"
					<< "1.By using two points.\n"
					<< "2.By using a point and a vector.\n";
				input_txt >> fun_choice;
				if (fun_choice == 1) {
					cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
					input_txt >> p >> p1;
					Line l(p, p1);
					pt_line = &l;

					cout << *pt_line;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this line:\n"
							<< "1.Find the direction of the line (returns the direction vector of the line).\n"
							<< "2.Find the normal vector of the line.\n"
							<< "3.Find the angle between two lines (in radians).\n"
							<< "4.Check if a point is on the line\n"
							<< "5.Check if a line is parallel to the first line.\n"
							<< "6.Check if a line is coinside with the first line.\n"
							<< "7.Check if two lines are intersected\n"
							<< "8.Check if two lines are crossed\n"
							<< "9.Check if a line is perpendicular to the first line.\n\n";
						input_txt >> fun_choice2;

						//line functions
						switch (fun_choice2) {
						case 1: {
							cout << "The direction of the line is a directional vector: " << pt_line->direction() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break; }
						case 2: {
							cout << "The normal vector of the line is vector: " << pt_line->normal_vector() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break;
						}
						case 4: {
							cout << "Please enter coordinates for the point: ";
							input_txt >> p2;
							if (*pt_line + p2 == true)
								cout << "The point is on the line.\n\n";
							else
								cout << "The point is not on the line.\n\n";

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break;
						}
						}
						if (fun_choice2 == 3) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 5) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 6) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 7) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}


							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 8) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 9) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

					} while (rep[0] == 'y');

				}
				else if (fun_choice == 2) {
					cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
					input_txt >> p >> v;
					Line l(p, v);
					pt_line = &l;

					cout << *pt_line;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this line:\n"
							<< "1.Find the direction of the line (returns the direction vector of the line).\n"
							<< "2.Find the normal vector of the line.\n"
							<< "3.Find the angle between two lines (in radians).\n"
							<< "4.Check if a point is on the line\n"
							<< "5.Check if a line is parallel to the first line.\n"
							<< "6.Check if a line is coinside with the first line.\n"
							<< "7.Check if two lines are intersected\n"
							<< "8.Check if two lines are crossed\n"
							<< "9.Check if a line is perpendicular to the first line.\n\n";
						input_txt >> fun_choice2;

						//line functions
						switch (fun_choice2) {
						case 1: {
							cout << "The direction of the line is a directional vector: " << pt_line->direction() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break; }
						case 2: {
							cout << "The normal vector of the line is vector: " << pt_line->normal_vector() << endl << endl;
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break;
						}
						case 4: {
							cout << "Please enter coordinates for the point: ";
							input_txt >> p2;
							if (*pt_line + p2 == true)
								cout << "The point is on the line.\n\n";
							else
								cout << "The point is not on the line.\n\n";

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
							break;
						}
						}
						if (fun_choice2 == 3) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								cout << "The angle between the two lines in radians is:" << pt_line->angle(*pt_line2) << endl;
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 5) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line || *pt_line2) == true)
									cout << "The lines are parallel.\n\n";
								else
									cout << "The lines aren't parallel.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 6) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line == *pt_line2) == true)
									cout << "The lines are coinside.\n\n";
								else
									cout << "The lines aren't coinside.\n\n";
							}

							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 7) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line && *pt_line2) == true)
									cout << "The lines are intersected.\n\n";
								else
									cout << "The lines aren't intersected.\n\n";
							}


							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 8) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line != *pt_line2) == true)
									cout << "The lines are crossed.\n\n";
								else
									cout << "The lines aren't crossed.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

						if (fun_choice2 == 9) {
							cout << "How would you like to initialize the second line:\n"
								<< "1.By using two points.\n"
								<< "2.By using a point and a vector.\n";
							input_txt >> fun_choice3;
							if (fun_choice3 == 1) {
								cout << "Enter 3 coordinates for two separate points in order to create the Line:\n";
								input_txt >> p >> p1;
								Line l2(p, p1);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							else if (fun_choice3 == 2) {
								cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Line:\n";
								input_txt >> p >> v;
								Line l2(p, v);
								pt_line2 = &l2;

								cout << *pt_line2;

								if ((*pt_line | *pt_line2) == true)
									cout << "The lines are perpendicular.\n\n";
								else
									cout << "The lines aren't perpendicular.\n\n";
							}
							cout << "Do you want to see another operation with this line? y / n\n";
							input_txt >> rep[0];
						}

					} while (rep[0] == 'y');
				}

				cout << "Do you want to see operations with another object?y / n\n";
				input_txt >> rep[0];
				break; }

				  //Segment
			case 4:

				cout << "How would you like to initialize the segment:\n"
					<< "1.By using two points.\n"
					<< "2.By using a point and a vector.\n";
				input_txt >> fun_choice;
				if (fun_choice == 1) {
					cout << "Enter 3 coordinates for two separate points in order to create the Segment:\n";
					input_txt >> p >> p1;
					Segment s(p, p1);
					pt_seg = &s;

					cout << *pt_seg;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this Segment:\n"
							<< "1.Find the lenght of the segment.\n"
							<< "2.Find the middle of the segment.\n"
							<< "3.Check if a point is on the segment\n\n";
						input_txt >> fun_choice2;
						switch (fun_choice2) {
						case 1: {
							cout << "The lenght of the segment is: " << pt_seg->getLength() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}

						case 2: {
							cout << "The middle of the segment is a point with coordinates: " << pt_seg->getMidpoint() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}

						case 3: {
							cout << "Please enter coordinates for the point: ";
							input_txt >> p2;
							if ((*pt_seg == p2) == true)
								cout << "The point is on the segment.\n\n";
							else
								cout << "The point is not on the segment.\n\n";

							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}
						}
					} while (rep[0] == 'y');
				}
				else if (fun_choice == 2) {
					cout << "Enter 3 coordinates for the point and 3 coordinates for the vector in order to create the Segment:\n";
					input_txt >> p >> v;
					Segment s(p, v);
					pt_seg = &s;

					cout << *pt_seg;

					do {
						cout << "Please choice an option for a specific operation you would like to see with this Segment:\n"
							<< "1.Find the lenght of the segment.\n"
							<< "2.Find the middle of the segment.\n"
							<< "3.Check if a point is on the segment\n\n";
						input_txt >> fun_choice2;
						switch (fun_choice2) {
						case 1: {
							cout << "The lenght of the segment is: " << pt_seg->getLength() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}

						case 2: {
							cout << "The middle of the segment is a point with coordinates: " << pt_seg->getMidpoint() << endl << endl;
							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}

						case 3: {
							cout << "Please enter coordinates for the point: ";
							input_txt >> p2;
							if ((*pt_seg == p2) == true)
								cout << "The point is on the segment.\n\n";
							else
								cout << "The point is not on the segment.\n\n";

							cout << "Do you want to see another operation with this segment? y / n\n";
							input_txt >> rep[0];
							break;
						}
						}
					} while (rep[0] == 'y');
				}

				cout << "Do you want to see operations with another object?y / n\n";
				input_txt >> rep[0];
				break;

				//Triangle
			case 5: cout << "Enter 3 cordinates for 3 separete points in order to create a Triangle:\n ";
				input_txt >> p >> p1 >> p2;
				t.makeTriangleFromPoints(p, p1, p2);
				do {
					cout << "Please choice an option for a specific operation you would like to see with this Triangle:\n"
						<< "1.Specify the triangle type.\n2.Calculate the triangle area.\n3.Calculate the triangle perimeter.\n4.Calculate the Point that is Centroid for the triangle.\n"
						<< "5.Check if a Point lies in the same plain and is within the Triangle.\n6.Check if a Point lies in the same plain and is not within the Triangle.\n7.Check if a Point lies on one of the Triangle's sides.\n";
					input_txt >> fun_choice;
					switch (fun_choice) {
						//Specify the triangle type
					case 1:
						//t.TriangleKind(t);
						t.Angle(t);
						t.strana(t);
						cout << "Do you want to see other operations with this Triangle?y / n\n";
						input_txt >> rep[0];
						break;
						//triangle area
					case 2:
						cout << "The area of Triangle with sides:" << t << " is " << t.TriangleArea();
						cout << ". Do you want to see other operations with this Triangle?y / n\n";
						input_txt >> rep[0];
						break;
						//triangle perimeter
					case 3:
						cout << "The perimeter of Triangle with sides:" << t << " is " << t.TrianglePerimeter();
						cout << "Do you want to see other operations with is Triangle?y / n\n";
						input_txt >> rep[0];
						break;
						//Calculate the Point that is Centroid
					case 4:
						cout << "The centroid of Triangle with sides: " << t << " is a Point with the following cordinates: " << t.calculateTriangleCentroid(t);
						cout << ". Do you want to see operations with this Triangle?y / n\n";
						input_txt >> rep[0];
						break;
						//Check if a Point lies in the same plain and is in the Triangle <
					case 5:
						cout << "Enter values for Point in order to check if its in the same plain and lies within the Triangle:\n";
						input_txt >> p;
						if (t < p) {
							cout << "Point " << p << " lies on the same plain as the Triangle and it is within the Triangle. Do you want to see other operations with this Triangle ? y / n\n";
							input_txt >> rep[0];
						}
						else {
							cout << "Point " << p << " is not within the Triangle.Do you want to see other operations with this Triangle ? y / n\n";
							input_txt >> rep[0];
						}
						break;
						//Check if a Point lies in the same plain and is not in the Triangle >
					case 6:
						cout << "Enter values for Point in order to check if its in the same plain and lies outside the Triangle:\n";
						input_txt >> p;
						if (t > p) {
							cout << "Point " << p << " lies on the same plain as the Triangle and it is not outside the Triangle. Do you want to see other operations with this Triangle ? y / n\n";
							input_txt >> rep[0];
						}
						else {
							cout << "Point " << p << " is not outside the Triangle. Do you want to see other operations with this Triangle?y / n\n";
							input_txt >> rep[0];
						}
						break;
						//Check if a Point lies on of the Triangle's sides. ==
					case 7:
						cout << "Enter values for Point in order to check if it lies on one of the Triangle's sides:\n";
						input_txt >> p;
						if (t == p) {
							cout << "Point " << p << " lies on one of Triangle's sides. Do you want to other see operations with this Triangle?y / n\n";
							input_txt >> rep[0];
						}
						else {
							cout << "Point " << p << " does not lie on one of Triangle's sides. Do you want to see other operations with this Triangle?y / n\n";
							input_txt >> rep[0];
						}
						break;
					}
				} while (rep[0] == 'y');

			case 6:
				cout << "Enter 4 value of the four Tetrahedron coordinates " << endl;
				input_txt >> p >> p1 >> p2 >> p3;
				Tetrahedron t3(p, p1, p2, p3);
				pt = &t3;
				cout << *pt;

				do {
					cout << "Please choosee an option for a specific operation you would like to see with this Tetrahedron:\n"
						<< "1.Check if Tetrahedron is Regular.\n2.Check Tetrahedron Surface.\n3.Check Tetrahedron Volume.\n"
						<< "4.Check if a point is inside the tetrahedron.\n"
						<< "5.Check if a point is on a boundary of the tetrahedron.\n"
						<< "6.Check if a point is on an edge of the tetrahedron.\n" << endl;
					input_txt >> fun_choice;
					switch (fun_choice) {
					case 1:
						//Tetrahedron regularity
						if (t3.isRegular()) {
							cout << "The Tetrahedron is regular.Do you want to see other operations with this Tetrahedron?y / n\n";
							input_txt >> rep[0];
							break;
						}
						else {
							cout << "The Tetrahedron is not regular.Do you want to see other operations with this Tetrahedron?y / n\n";
							input_txt >> rep[0];
							break;
						}
						//surface
					case 2:
						cout << setprecision(5) << "The surface of the Tetrahedron is " << t3.getSurface() << " .\n";
						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						input_txt >> rep[0];
						break;
					case 3:
						cout << "The volume of the Tetrahedron is " << setprecision(5) << t3.getVolume(p, p1, p2, p3) << " .\n";
						cout << "Do you want to see other operations with this Tetrahedron?y / n\n";
						input_txt >> rep[0];
						break;
					}

				} while (rep[0] == 'y');

				cout << "Do you want to see operations with another object?y / n\n";
				input_txt >> rep[0];
				break;
			}

		} while (rep[0] == 'y');
	}
	//#endif
	return 0;
}