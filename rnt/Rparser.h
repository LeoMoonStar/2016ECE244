
#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include"Node"
#include"Resistor"
using namespace std;
class Parser(){
private:
  string line,command,name;
  int maxNodeNumber,maxResistors;
  double resistance;
  int nodeid1,nodeid2;
  int currentResistorSize,currentNodeSize;
public:
  Parser();//constructor
  ~Parser();//Decondstructor
  void Rparser();
  void maxVal(string line);
  void functionSelect(string line);
  void insertR(string line);
  void modifyR(string line);
  void printR(string line);
  void printNode(string line);
  void deleteR(string line);
  int countTheWord(string line);
  int judgeTypeOfWord(string line);
  bool nameNoExist(string name);
  void trim(string & s);
  int getResistanceIndex(string name);
}
