/* 
 * File:   ResistorList.h
 * Author: yangjiaw
 *
 * Created on November 8, 2016, 2:18 PM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H
#include "Resistor.h"
class ResistorList {
public:
    ResistorList();
    ~ResistorList();
private:
    Resistor r;
    Resistor* next;
};

#endif	/* RESISTORLIST_H */

