
#ifndef RESISTOR_H
#define RESISTOR_H
#include<iostream>
#include<string>
using namespace std;

class Resistor
{
private:
	string name;
	double resistance;
	int endpoints[2];
	Resistor* nextR;
public:
	Resistor();
	Resistor(string nm, double res, int endpoints[2]);
	~Resistor();
	int getEndPoint(int i);
	Resistor* returnNext();
};
#endif /*RESISTOR_H*/
