#pragma once
#include<iostream>
#include<string>
#include<exception>
using namespace std;
class EqualPointException : public exception
{
	//Todo: koi tochki suvpadat?
public:
	virtual const string msgTr() {
		return "Can not construct a figure with equal points!";
	}

};
