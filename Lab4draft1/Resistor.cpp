#include "Resistor.h"



Resistor::Resistor()
{
	name = "";
	resistance = 0.0;
	endpoints[0] = 0;
	endpoints[1] = 0;
	nextR = NULL;
}

Resistor::Resistor(Resistor& newWord) {
	name = newWord.getName();
	resistance = newWord.getResistance();
	endpoints[0] = newWord.getEndPoint(0);
	endpoints[1] = newWord.getEndPoint(1);
	nextR = newWord.returnNext();
}
Resistor::Resistor(string nm, double res, int endpoints_[2]) {
	name = nm;
	resistance = res;
	for (int i = 0; i < 2; i++)
	{
		endpoints[i] = endpoints_[i];
	}
	nextR = NULL;
}
int Resistor::getEndPoint(int i) {
	return endpoints[i];
}
Resistor* Resistor::returnNext() {
	return nextR;
}

string Resistor::getName() {
	return name;
}
void Resistor::modifyResistance(double newRes) {
	resistance = newRes;
}
double Resistor::getResistance() {
	return resistance;
}

void Resistor::addResistor(Resistor* newResistor) {
	nextR = newResistor;
}

void Resistor::printResistor() {
	cout << setfill(' ') << setw(20);//sets the output
	cout << left << name;
	cout << " ";
	cout << setfill(' ') << setw(8);
	cout << right << resistance;
	cout << ' ' << "Ohms " << getEndPoint(0) << " -> " << getEndPoint(1) << endl;
}
Resistor::~Resistor(){}