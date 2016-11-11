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
	bool setV;
	int resNumber;

public:
	Node();
	Node(int i);
	~Node();
	int getId();
	int getResNumb();
	double getVoltage();
	void setId(int id);
	void setVoltage(double v);
	Node* returnNext()const;
	void setNext(Node*newNode);
	ResistorList* returnRlHead();
	void addNode(Node * newNode);
	void deleteOneResistor();
	void addResistor(Resistor* newRes);
	bool voltageseted();
	void nodePrint();
	void unsetV();
	void setVoltagebysolve(double v);
	int returnResNumber();
	
};
double returnAbsValue(double a);
#endif // !NODE_H