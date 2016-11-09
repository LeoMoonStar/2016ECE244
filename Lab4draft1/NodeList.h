#ifndef NODELIST_H
#define NODELIST_H
#include"Node.h"
#include"ResistorList.h"
class NodeList
{
private:
	Node* head;
public:
	NodeList();
	~NodeList();
	Node* returnHead();
};

#endif