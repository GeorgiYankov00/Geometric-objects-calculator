#pragma once
#include<iostream>
#include<exception>
#include<string>

class VectorLenghtException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Vector length can't be 0! \n";
	}

};