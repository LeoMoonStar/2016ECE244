#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include"Node"
#include"Resistor"
using namespace std;

Resistor *arrayResistor=NULL; //globe resistor array
Node *arrayNode=NULL;//globe node array


void Parser::Parser(){
maxResistors=0;
maxNodeNumber;
line="";
command="";
}

void Parser::Rparser(){
  Parser obj;
  while(!cin.eof()){
          cout<<"> ";
          getline(cin,line);
          functionSelect(line);
        }
        delete []arrayResistor;
        delete []arrayNode;
      }

void Pparser::functionSelect(string line){
  stringstream ss(line);
  ss>>command;
  switch (command) {
    case "insertR":insertR(line);
    break;
    case "modifyR":modifyR(line);
    break;
    case "printR":printR(line);
    break;
    case:"printNode":printNode(line);
    break;
    case "deleteR":deleteR(line);
    break;
    case "maxVal":maxVal(line);
    break;
    default:
    std::cout << "Error: invalid command" << std::endl;
  }
}
void Rparser::maxVal(string line){
  stringstream ss(line);
  ss>>command>>maxNodeNumber>>maxResistors;
  if((maxNodeNumber>0)&&(maxResistors)){
    cout<<"New network: max node number is "<<maxNodeNumber<<"; max resistors is "<<maxResistors<<endl;
    arrayNode=new Node[maxNodeNumber];
    arrayResistor= new Resistor[maxResistors];
  }
  else
  {
    cout<<"Error: maxVal arguments must be greater than 0"<<endl;
    maxNodeNumber=0;
    maxResistors=0;
  }
}

void Rparser::insertR(string line){
  stringstream ss(line);
  ss>>command>>resistance>>nodeid1>>nodeid2;
    
}
