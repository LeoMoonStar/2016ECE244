#ifndef RESISTORLIST_H
#define RESISTORLIST_H
#include"Resistor.h"

class ResistorList
{
private:
	Resistor *head;
public:
	ResistorList();
	~ResistorList();
};

#endif // !RESISTORLIST_H