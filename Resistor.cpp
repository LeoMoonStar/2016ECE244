
#include <string>
#include <iostream>
#include <iomanip>
#include "Resistor.h"
using namespace std;
//Constructor: Initializes everything to zero
Resistor::Resistor()
{
    resistance = 0;
    for(int i =0; i<2 ; i++)
    {
        endpointNodeIDs[i] = 0;
    }
    name = "";
}


Resistor::Resistor(int rIndex_,string name_,double resistance_,int endpoints_[2])
{
    resistance = resistance_;
    name = name_;
    for(int i = 0; i<2 ; i++)
    {
        endpointNodeIDs[i] = endpoints_[i];

    }

}


string Resistor::getName() const
{
    return name;
}


double Resistor::getResistance() const
{
    return resistance;
}

//Mutator to write a new value to the resistance
void Resistor::setResistance(double newResistance)
{
    resistance = newResistance;

}
//Function to print the details of a resistor object
void Resistor::print()
{
    cout << setfill (' ') << setw (20); //Sets the output stream's field witdth
    cout << left << name; // the output is alligned to left
    cout<<' ';
    cout << setfill (' ') << setw (8);
    cout << right << resistance; // the output is alligned to right
    cout<<' ';
    cout<<"Ohms ";
    cout<<endpointNodeIDs[0]<<" -> "<< endpointNodeIDs[1]<<endl;

}

void Resistor::deleteR()
{
    resistance = 0;
    for(int i =0; i<2 ; i++)
    {
        endpointNodeIDs[i] = 0;
    }
    name = "";

}
//Destructor
Resistor::~Resistor(){}
