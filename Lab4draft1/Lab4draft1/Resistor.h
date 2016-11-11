
#ifndef RESISTOR_H
#define RESISTOR_H
#include<iostream>
#include<string>
#include<iomanip>
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
	Resistor( Resistor& newWord);
	Resistor(string nm, double res, int endpoints[2]);
	~Resistor();
	int getEndPoint(int i);
	string getName();
	double getResistance();
	void addResistor(Resistor* newResistor);
	Resistor* returnNext();
	void modifyResistance(double newRes);
	void printResistor();

};
#endif /*RESISTOR_H*/
