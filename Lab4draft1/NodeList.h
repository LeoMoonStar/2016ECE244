#ifndef NODE_LIST.H
#defin NODE_LIST.H
#include"Node.h"
#include"ResistorList"

class NodeList
{
private:
	Node node;
	int id;
	ResistorList Rlist;
	Node* next;
public:
	NodeList();
	~NodeList();
};
#endif
