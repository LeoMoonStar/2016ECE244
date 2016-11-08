

#ifndef RPARSER_H
#define RPARSER_H
#include <iostream>
#include <string>
#include "Resistor.h"
#include "Node.h"
using namespace std;

class Parser
{
private:
    
    string  command, name;
    char line[300];
    int letters;
    double resistance;
    int node1, node2;
    int count;
    int maxNodeNumber; 
    int maxResistors; 
    int resistorIndex;
    int newMaxNode;


public:
    Parser();
    bool input(string word); 
    void insertR(string line); 
                                
    void modifyR(string line); 
                           
    void printR(string line);
                                
    void printNode(string line); 
                                
    void deleteR(string line); 
                                
    void maxVal(string line); 
};
//Checks the input and builds the network
void Rparser();
#endif /* defined(__Rparser__Rparser__) */
