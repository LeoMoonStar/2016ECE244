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
}
Node::Node(int id) {
	NodeId = id;
	voltage = 0.0;


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
}

Node::~Node() {
}

Node* Node::returnNext() {
	return nextNode;
}