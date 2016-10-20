
#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include"Node"
#include"Resistor"
using namespace std;
class Rparser(){
private:
  string line,command,name;
  int maxNodeNumber,maxResistors;
  double resistance;
  int nodeid1,nodeid2;





  void Rparser();
  void functionSelect(string line);
}
