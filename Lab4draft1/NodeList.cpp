#include "NodeList.h"



NodeList::NodeList()
{
	head = NULL;
}


NodeList::~NodeList()
{
}

Node* NodeList::returnHead() {
	return head;
}