#include "ResistorList.h"



ResistorList::ResistorList()
{
	head = NULL;//initialises head to NULL
}
Resistor* ResistorList::returnHead() const{
	return head;
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

bool ResistorList::resistorExist(string name) {
	Resistor *temp = head;
	bool a = false;
	while (temp != NULL) {
		if (temp->getName() == name) 
			a = true;
		temp = temp->returnNext();
	}
	return a;
}

void ResistorList::deleteResistor(string resistor) {
	Resistor* current = head;
	Resistor* previous = NULL;
	while (current!=NULL && current->getName() != resistor) {
		previous = current;
		current = current->returnNext();
	}
	Resistor* temp = current;
	current = current->returnNext();
	previous->returnNext()->addResistor(current);
	delete temp;
}

void ResistorList::deleteAllResistor() {
	Resistor* current = head;
	Resistor* previous = NULL;
	while (current != NULL) {
		previous = current;
		current = current->returnNext();
		delete previous;
	}
	head = NULL;
}

void ResistorList::insertNewResistor(Resistor* newResistor) {
	if (head == NULL)
		head = newResistor;
	else
	{
		Resistor* temp = head;
		while (temp->returnNext() != NULL)
			temp = temp->returnNext();
		temp->addResistor(newResistor);
	}
}
/*ResistorList::~ResistorList() {
	Resistor *current = head;
	Resistor *previous = NULL;
	while (current != NULL) {
		previous = current;
		current = current->returnNext();
		delete previous;
	}
	head = NULL;
}*/

