#include "ResistorList.h"



ResistorList::ResistorList()
{
	head = NULL;
}


ResistorList::~ResistorList()
{
	Resistor *current = head;
	while (current != NULL) {
		Resistor *previous = NULL;
		previous= current;
		current = current->returnNext();
		delete previous;
	}
	head = NULL;
}
