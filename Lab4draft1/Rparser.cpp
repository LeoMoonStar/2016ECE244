/*
* File:   Rparser.cpp
* Author: yangjiaw
*
* Created on November 8, 2016, 2:18 PM
*/

#include "Rparser.h"
using namespace std;
Rparser::Rparser() {
	command = "";
	name = "";
	nodeid1 = 0;
	nodeid2 = 0;
	voltage = 0.0;
}

Rparser::~Rparser() {//leave it at last part to avoid memoryleak
}
void parser() {
	Rparser obj;
	string line;
	cout << "> ";
	getline(cin, line);
	while (!cin.eof()) {
		obj.functionSelect(line);
		cout << "> ";
		getline(cin, line);
	}

}

void Rparser::functionSelect(string line) {
	command = "";
	name = "";
	nodeid1 = 0;
	nodeid2 = 0;
	voltage = 0.0;
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
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	bool a = true;
	bool b = true;
	int resnodes[2];
	resnodes[0] = nodeid1;
	resnodes[1] = nodeid2;
	Resistor *resnode1 = new Resistor(name, resistance, resnodes);
	Resistor *resnode2 = new Resistor(name, resistance, resnodes);
	
	if (nodeList.resistorExistAllNodeList(name)) {
		cout << "Error: resistor " << name << " already exists" << endl;
	}
	else
	{
		if (!nodeList.nodeIdexist(nodeid1)) {
			Node* newNode = new Node(nodeid1);
			nodeList.insertNewNode(newNode);
			newNode->addResistor(resnode1);
		}
		else {
			Node*temp = nodeList.returnHead();
			while (temp->getId() != nodeid1) {
				temp = temp->returnNext();
			}
			temp->returnRlHead()->insertNewResistor(resnode1);

		}
		if (!nodeList.nodeIdexist(nodeid2)) {
			Node* newNode = new Node(nodeid2);
			nodeList.insertNewNode(newNode);
			newNode->addResistor(resnode2);
		}
		else {
			Node*temp = nodeList.returnHead();
			while (temp->getId() != nodeid2) {
				temp = temp->returnNext();
			}
			temp->returnRlHead()->insertNewResistor(resnode2);

		}
		cout << "Inserted: resistor " << name << " " << resistance << " Ohms " << nodeid1 << " -> " << nodeid2 << endl;

	}
}

void Rparser::modifyR(string line) {
	double oldResistence;
	stringstream ss(line);
	ss >>command>>name >> resistance;
	Node*temp = nodeList.returnHead();
	bool changeDisplayed = false;
	if(!nodeList.resistorExistAllNodeList(name))
		cout << "Error: resistor " << name << " not found" << endl;
	else {
		while (temp != NULL) {
			if (temp->returnRlHead()->resistorExist(name)) {
				Resistor*a;
				a = temp->returnRlHead()->returnHead();
				while (a->getName() != name) {
					a = a->returnNext();
				}
				oldResistence = a->getResistance();
				a->modifyResistance(resistance);
			}
			temp = temp->returnNext();
		}
		cout << "Modified: Resistor " << name << " from " << oldResistence << " Ohms to " << resistance << " Ohms" << endl;
	}
}


void Rparser::setV(string line) {
	stringstream ss(line);
	ss >> command >> nodeid1 >> voltage;
	Node*previous = nodeList.returnHead();
	while (previous!= NULL) {
		if (previous->getId() == nodeid1) {
			previous->setVoltage(voltage);
			cout << "Set: node " << nodeid1 << " to " << voltage << " Volts" << endl;
		}
		previous = previous->returnNext();
	}
}

void Rparser::unsetV(string line) {
	stringstream ss(line);
	ss >> command >> nodeid1;
	Node*previous = nodeList.returnHead();
	while (previous != NULL) {
		if (previous->getId() == nodeid1)
		{
			previous->unsetV();
			cout << "Unset: the solver will determine the voltage of node " << nodeid1 << endl;
		}
		previous = previous->returnNext();
	}
}

void Rparser::printR(string line) {
	stringstream ss(line);
	ss >> command >> name;
	bool displayed = false;
	Node*temp = nodeList.returnHead();
	while (temp != NULL) {
		Resistor*a = temp->returnRlHead()->returnHead();
		if (temp->returnRlHead()->resistorExist(name)) {	
			while (a->getName() != name)
				a = a->returnNext();
		}
		if (!displayed) {
			a->printResistor();
			displayed = true;
		}
		temp = temp->returnNext();
	}
}


void Rparser::printNode(string line) {
	stringstream ss(line);
	string what;
	ss >> command >> what;
	if (what == "all") {
		cout << "Print:" << endl;
		Node*temp = nodeList.returnHead();
		while (temp != NULL) {
			temp->nodePrint();
			temp = temp->returnNext();
		}
	}
	else {
		stringstream ss(line);
		ss >> command >> nodeid1;
		Node*temp = nodeList.returnHead();
		while((temp->getId() != nodeid1)&&(temp!=NULL)) {
			temp = temp->returnNext();
		}
		if (temp->getId() == nodeid1)
			temp->nodePrint();
		else if (temp = NULL)
			cout << "Error: node " << nodeid1 << " not found" << endl;
	}
	
	

}
void Rparser::solve(string line) {
	stringstream ss(line);
	ss >> command;
	if (nodeList.checkForVoltage()) {
		cout << "Error: no nodes have their voltage set" << endl;
	}
	else
	{
		cout << "Solve:" << endl;
		nodeList.solve();
		nodeList.printVoltage();
	}
}

void Rparser::delet(string line) {
	stringstream ss(line);
	ss >> command >> name;
	if (name == "all") {
		Node* temp = nodeList.returnHead();
		while (temp != NULL) {
			temp->returnRlHead()->deleteAllResistor();
			temp = temp->returnNext();
		}
		nodeList.deleteNodeAll();
		cout << "Deleted: all resistors" << endl;
	}
	else
	{
		if (!nodeList.resistorExistAllNodeList(name))
			cout << "Error: resistor " << name << " not found" << endl;
		else
		{
			Node* temp = nodeList.returnHead();
			while (temp!=NULL) {
				if (temp->returnRlHead()->resistorExist(name))
				{
					temp->returnRlHead()->deleteResistor(name);
					temp->deleteOneResistor();
				}
				temp = temp->returnNext();
				}
			cout << "Deleted: resistor " << name << endl;

			}
		}
	}