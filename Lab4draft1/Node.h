#pragma once
#ifndef NODE_H
#define NODE_H

#include"Resistor.h"
#include"ResistorList.h"
class Node
{
private:
	int NodeId;
	double voltage;
	ResistorList* r;
	Node* nextNode;

public:
	Node();
	Node(int i);
	~Node();
	int getId();
	double getVoltage();
	void setId(int id);
	void setVoltage(double v);
	Node* returnNext();
};

#endif // !NODE_H