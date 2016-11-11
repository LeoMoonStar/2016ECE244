#include "NodeList.h"



NodeList::NodeList()
{
	head = NULL;
}


NodeList::~NodeList()
{
	Node *current = head;
	Node* previous = NULL;
	while (current != NULL) {
		previous = current;
		current = current->returnNext();
		delete previous;
	}
	head = NULL;
}

Node* NodeList::returnHead() {
	return head;
}

bool NodeList::nodeIdexist(int id) {
	bool exist = false;
	Node* current = head;
	while (current != NULL) {
		if (current->getId() == id)
			exist = true;
		current = current->returnNext();
	}
	return exist;
}

bool NodeList::resistorExistAllNodeList(string name) {
	Node* temp = head;
	bool a = false;
	while (temp != NULL) {
		if (temp->returnRlHead()->resistorExist(name))
			a=true;
		temp = temp->returnNext();
	}
	return a;
}
void NodeList::deleteNodeAll() {
	Node*current = head;
	Node *previous = NULL;
	while (current != NULL) {
		previous = current;
		current = current->returnNext();
		delete previous;
	}
	head = NULL;
}
bool NodeList::checkForVoltage() {
	Node* current = head;
	bool a = true;
	while (current != NULL) {
		if (current->getVoltage() != 0)
			a = false;
		current = current->returnNext();
	}
	return a;
}

void NodeList::printVoltage() {
	Node* current = head;
	while (current != NULL) {
		cout << "  ";
		cout << "Node " << current->getId() << ": " << current->getVoltage() << " V" << endl;
		current = current->returnNext();
	}
}

void NodeList::solve() {//finally work
	MIN_ITERATION_CHANGE = 2;
	while (MIN_ITERATION_CHANGE > 0.0001) {
		double v = 0;
		MIN_ITERATION_CHANGE = 0;
		Node*current = head;
		while (current!=NULL)
		{
			if (!current->voltageseted()) {
				int resNum = current->getResNumb();
				double res[10];
				double vol[10];
				Resistor *temp = current->returnRlHead()->returnHead();
				int i = 0;
				while (temp != NULL) {
					res[i] = temp->getResistance();
					int anotherNodeId;
					if (temp->getEndPoint(0) == current->getId())
						anotherNodeId = temp->getEndPoint(1);
					else
						anotherNodeId = temp->getEndPoint(0);
					Node*p = head;
					while (p->getId() != anotherNodeId) {
						p = p->returnNext();
					}
					vol[i] = p->getVoltage();
					i++;
					temp = temp->returnNext();
				}
				double part1 = 0;
				for (int i = 0; i < resNum; i++) {
					part1 = 1 / res[i] + part1;
				}
				double part2 = 0;
				for (int i = 0; i < resNum; i++) {
					part2 = part2 + (vol[i] / res[i]);
				}
				double change = current->getVoltage() - ((1 / part1)*part2);
				if ((MIN_ITERATION_CHANGE < returnAbsValue(change)) || (MIN_ITERATION_CHANGE == returnAbsValue(change)))
					MIN_ITERATION_CHANGE = returnAbsValue(change);
				current->setVoltagebysolve((1 / part1)*part2);
			}
			current = current->returnNext();
		}
	}


}

void NodeList::insertNewNode(Node* newNode) {
	
	
	int tempnode = newNode->getId();
	Node *current = head;
	Node *previous = NULL;
	while (current != NULL && current->getId() < tempnode) {
		previous = current;
		current = current->returnNext();
	}
	newNode->setNext(current);
	if (previous == NULL)
		head = newNode;
	else
		previous->setNext(newNode);
}

double returnAbsValue(double a) {
	if ((a > 0) || a == 0)
		return a;
	else
		return (0 - a);
}