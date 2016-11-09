/*
* File:   Rparser.cpp
* Author: yangjiaw
*
* Created on November 8, 2016, 2:18 PM
*/

#include "Rparser.h"
using namespace std;
Rparser::Rparser() {
	line = "";
	command = "";
	name = "";
	nodeid1 = 0;
	nodeid2 = 0;
	voltage = 0.0;
}

Rparser::~Rparser() {//leave it at last part to avoid memoryleak
}
void Rparser::parser() {
	while (!cin.eof()) {
		cout << "> ";
		getline(cin, line);
		functionSelect(line);
	}

}

void Rparser::functionSelect(string line) {
	stringstream ss(line);
	ss >> command;
	if(command=="insertR")
		insertR(line);
	else if(command=="modifyR")
		modifyR(line);
	else if(command=="setV")
		setV(line);
	else if(command=="unsetV")
		unsetV(line);
	else if(command=="solve")
		solve(line);
	
	else if(command=="deleteR")
		delet(line);
	else if (command=="printR")
		printR(line);
	else if(command=="printNode")
		printNode(line);
	else
		std::cout << "Error: invalid command" << std::endl;
	}


void Rparser::insertR(string line) {
	stringstream ss(line);
	ss >> command >> name >> resistance >> nodeid1 >> nodeid2;
	int resnodes[2];
	resnodes[0] = nodeid1;
	resnodes[1] = nodeid2;
	Resistor *resnode1 = new Resistor(name, resistance, resnodes);
	Resistor *resnode2 = new Resistor(name, resistance, resnodes);
	Node* temp = nodeList.returnHead();
	if (temp == NULL) {
		Node *node_1 = new Node(node1);
	}

}
void Rparser::modifyR(string line) {

}
void Rparser::setV(string line) {
	stringstream ss(line);
	ss >> command >> nodeid1 >> voltage;
	Node*previous = nodeList.returnHead();
	while (previous!= NULL) {
		if (previous->getId == nodeid1) {
			previous->setVoltage(voltage);
			cout << "Set: node " << nodeid1 << " to " << voltage << " Volts" << endl;
		}
		previous = previous->returnNext;
	}
}

void Rparser::unsetV(string line) {
	stringstream ss(line);
	ss >> command >> nodeid1;
	Node*previous = nodeList.returnHead();
	while (previous != NULL) {
		if (previous->getId == nodeid1)
		{
			previous->setVoltage(0);
			cout << "Unset: the solver will determine the voltage of node " << nodeid1 << endl;
		}
		previous = previous->returnNext;
	}
}
void Rparser::delet(string line) {

}
void Rparser::printR(string line) {

}
void Rparser::printNode(string line) {

}
void Rparser::solve(string line) {

}



