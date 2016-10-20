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
maxNodeNumber=0;
resistance=0.0;
line="";
command="";
nodeid1=0;
nodeid2=0;
currentResistorSize=0;
currentNodeSize=0;
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

void Parser::functionSelect(string line){
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
void Parser::maxVal(string line){
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

void Parser::insertR(string line){
  if (numberOfWords(line) == 1)
          cout << "Error: too few arguments" << endl;
      if (numberOfWords(line) == 2) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else
              cout << "Error: too few arguments" << endl;
      }
      if (numberOfWords(line) == 3) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else {
              stringstream ss(line);
              ss >> command >> name >> resistance;
              if (!ss.fail()) {
                  if (resistance < 0)
                      cout << "Error: negative resistance" << endl;
                  else
                      cout << "Error: too few arguments" << endl;
              } else {
                  cout << "Error: invalid argument" << endl;
                  ss.clear();
              }
          }
      }
      if (numberOfWords(line) == 4) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all") {
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          } else {
              ss >> resistance;
              if (!ss.fail()) {
                  ss.clear();
                  ss >> nodeid1;
                  if (!ss.fail()) {
                      if (nodeid1 < 0 || nodeid1 > 5000)
                          cout << "Error: node " << nodeid1 << " is out of permitted range 0-5000" << endl;
                      else
                          cout << "Error: too few arguments" << endl;
                  } else
                      cout << "Error: invalid argument" << endl;
              }
          }
      }
      if (numberOfWords(line) == 5) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else {
              ss >> resistance;
              if (!ss.fail()) {
                  ss.clear();
                  if (resistance < 0)
                      cout << "Error: negative resistance" << endl;
                  else {
                      ss >> nodeid1;
                      if (!ss.fail()) {
                          if (nodeid1 < 0 || nodeid1 > maxNodeNumber)
                              cout << "Error: node " << nodeid1 << " is out of permitted range 0-" <<maxNodeNumber<<endl;
                          else {
                              ss.clear();
                              getline(ss, s2);
                              if (judgeTypeOfWord(s2) == 1) {
                                  trim(s2);
                                  stringstream ss(s2);
                                  ss >> nodeid2;
                                  ss.clear();
                                  if (nodeid2 < 0 || nodeid2 > maxNodeNumber)
                                      cout << "Error: node " << nodeid2 << " is out of permitted range 0-"<<maxNodeNumber<<endl;
                                  else if (nodeid1 != nodeid2) {
                                      cout << "Inserted: resistor " << name << " " << setprecision(2) << fixed << resistance << " Ohms "
                                              << nodeid1 << " -> " << nodeid2 << endl;
                                              
                                  } else if (nodeid1 == nodeid2)
                                      cout << "Error: both terminals of resistor connect to node " << nodeid1 << endl;
                              } else
                                  cout << "Error: invalid argument" << endl;
                          }
                      } else
                          cout << "Error: invalid argument" << endl;
                  }
              } else
                  cout << "Error: invalid argument" << endl;
          }
      }
      if (numberOfWords(line) > 5) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else {
              ss >> resistance;
              if (!ss.fail()) {
                  ss.clear();
                  if (resistance < 0)
                      cout << "Error: negative resistance" << endl;
                  else {
                      ss >> nodeid1;
                      if (!ss.fail()) {
                          if (nodeid1 < 0 || nodeid1 > 5000)
                              cout << "Error: node " << nodeid1 << " is out of permitted range 0-5000" << endl;
                          else {
                              ss.clear();
                              getline(ss, s2);
                              if (judgeTypeOfWord(s2) == 1) {
                                  trim(s2);
                                  stringstream ss(s2);
                                  ss >> nodeid2;
                                  ss.clear();
                                  if (nodeid2 < 0 || nodeid2 > 5000)
                                      cout << "Error: node " << nodeid2 << " is out of permitted range 0-5000" << endl;
                                  else if (nodeid1 != nodeid2) {
                                      cout << "Error: too many arguments" << endl;
                                  } else if (nodeid1 == nodeid2)
                                      cout << "Error: both terminals of resistor connect to node " << nodeid1 << endl;
                              } else
                                  cout << "Error: invalid argument" << endl;
                          }
                      } else
                          cout << "Error: invalid argument" << endl;
                  }
              } else
                  cout << "Error: invalid argument" << endl;
          }
      }

  }

int Parser::countTheWord(string line){
  int numberOfWords(string line) {
    stringstream ss(line);
    string whatever;
    int number = 0;
    while (!ss.eof()) {
        ss >> whatever;
        if (!ss.fail())
            number++;
    }
    return number;
}
}
