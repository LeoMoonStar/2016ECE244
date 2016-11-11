#ifndef NODELIST_H
#define NODELIST_H
#include"Node.h"
#include"ResistorList.h"

class NodeList
{
private:
	Node* head;
	double MIN_ITERATION_CHANGE;
public:
	NodeList();
	~NodeList();
	bool resistorExistAllNodeList(string name);
	Node* returnHead();
	bool nodeIdexist(int id);
	void deleteNodeAll();
	bool checkForVoltage();
	void solve();
	void printVoltage();
	void insertNewNode(Node* newNode);
};

#endif