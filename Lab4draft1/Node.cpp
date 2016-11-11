/*
* File:   Node.cpp
* Author: yangjiaw
*
* Created on November 8, 2016, 2:17 PM
*/

#include "Node.h"

Node::Node() {
	NodeId = 0;
	voltage = 0.0;
	r = new ResistorList;
	nextNode = NULL;
	setV = false;
	resNumber = 0;
}
Node::Node(int id) {
	NodeId = id;
	voltage = 0.0;
	r = new ResistorList;
	nextNode = NULL;
	setV = false;
	resNumber = 0;
}

ResistorList* Node::returnRlHead() {
	return r;
}
int Node::getId() {
	return NodeId;
}

double Node::getVoltage() {
	return voltage;
}

void Node::setId(int id) {
	NodeId = id;
}
void Node::setVoltage(double v) {
	voltage = v;
	setV = true;
}

Node::~Node() {
	delete r;
	r = NULL;
}

Node* Node::returnNext()const {
	return nextNode;
}

void Node::addNode(Node* newNode) {
	nextNode = newNode;
	
}

void Node::addResistor(Resistor*newRes) {
	r->insertNewResistor(newRes);
	resNumber++;
}

void Node::setNext(Node*newNode) {
	nextNode = newNode;
}

bool Node::voltageseted() {
	return setV;
}
void Node::deleteOneResistor() {
	resNumber--;
}
void Node::nodePrint() {
	cout << "Connections at node " << NodeId << ": " << resNumber << " resistor(s)" << endl;
	Resistor* temp = r->returnHead();
	while (temp != NULL) {
		temp->printResistor();
		temp = temp->returnNext();
	}
}
int Node::getResNumb() {
	return resNumber;
}
void Node::unsetV() {
	voltage = 0;
	setV = false;
}