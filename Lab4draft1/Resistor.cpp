#include "Resistor.h"



Resistor::Resistor()
{
	name = "";
	resistance = 0.0;
	endpoints[0] = 0;
	endpoints[1] = 0;
	nextR = NULL;
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


Resistor::~Resistor(){}