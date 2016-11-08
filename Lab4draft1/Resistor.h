#pragma once
#ifndef RESISTOR_H
#define RESISTOR_H
const int MAX_LENGTH_OF_NAME = 100;
class Resistor
{
private:
	char name[MAX_LENGTH_OF_NAME];
	double resistence;
	int firstNode;
	int lastNode;
public:
	Resistor();
	~Resistor();
};
#endif /*RESISTOR_H*/
