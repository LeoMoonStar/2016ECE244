#pragma once
#ifndef NODE_H
#define NODE_H

#include"Resistor.h"
class Node
{
private:
	double voltage;
	Resistor *header;

public:
	Node();
	~Node();
	void setVoltage();
};

#endif // !NODE_H
