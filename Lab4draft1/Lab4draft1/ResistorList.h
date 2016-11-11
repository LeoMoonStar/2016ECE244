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
	Resistor* returnHead()const;
	void deleteAllResistor();
	void deleteResistor(string resistor);
	void insertNewResistor(Resistor* newResistor);//insert a new resistor at the end
	bool resistorExist(string name);
};

#endif // !RESISTORLIST_H