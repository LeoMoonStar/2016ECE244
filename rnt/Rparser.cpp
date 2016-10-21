#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include <sstream>
#include<string>
#include<iomanip>
#include"Rparser.h"
using namespace std;

Resistor *arrayResistor=NULL; //globe resistor array
Node *arrayNode=NULL;//globe node array


Parser::Parser(){//constructor
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

void Parser::insertR(string line){//still dont know when to judge the name exist error
  if (numberOfWords(line) == 1)
          cout << "Error: too few arguments" << endl;
      if (numberOfWords(line) == 2) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else if(nameNoExist(name))
              cout << "Error: too few arguments" << endl;
      }
      if (numberOfWords(line) == 3) {
          stringstream ss(line);
          ss >> command >> name;
          if (name == "all")
              cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
          else if(nameNoExist(name)){
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
          } else if(nameNoExist(name)) {
              ss >> resistance;
              if (!ss.fail()) {
                  ss.clear();
                  ss >> nodeid1;
                  if (!ss.fail()) {
                      if (nodeid1 < 0 || nodeid1 > maxNodeNumber)
                          cout << "Error: node " << nodeid1 << " is out of permitted range 0-" <<maxNodeNumber<<endl;
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
          else if(nameNoExist(name)){
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
                                    if(arrayNode[nodeid1].canAddResistor(currentResistorSize)&&
                                    arrayNode[nodeid2].canAddResistor(currentResistorSize)){
                                      arrayResistor[currentResistorSize].setName(name);
                                      arrayResistor[currentResistorSize].setResistance(resistance);
                                      arrayResistor[currentResistorSize].setEndPoint(nodeid1,noid2);
                                      cout << "Inserted: resistor " << arrayResistor[currentResistorSize].getName() << " " << setprecision(2) << fixed
                                      << arrayResistor[currentResistorSize].getResistance() << " Ohms "
                                              << arrayResistor[currentResistorSize].getEndPoint1() << " -> " << arrayResistor[currentResistorSize].getEndPoint2() << endl;
                                                currentResistorSize++;
                                            }

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
          else if(nameNoExist(name)){
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

void Parser::modifyR(string line){
    trim(line);
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> name;
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
            ss >> resistance;
            if (!ss.fail() && ss.eof()) {
                if (resistance < 0)
                    cout << "Error: negative resistance" << endl;
                else{
                  int index=getResistanceIndex(name);
                  double oldResistance=arrayResistor[index].getResistance();
                  arrayResistor[index].setResistance(resistance);
                    cout << "Modified: resistor " << arrayResistor[index].getname() <<" from "<<
                    setprecision(2) << fixed<<oldResistance
                    " to " << setprecision(2) << fixed << arrayResistor[index].getResistance() << " Ohms" << endl;
                  }
            } else {
                cout << "Error: invalid argument" << endl;
                ss.clear();
            }
        }
    }

    if (numberOfWords(line) > 3) {
        stringstream ss(line);
        ss >> command >> name;
        if (name == "all")
            cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
        else {
            ss >> resistance;
            if (!ss.fail()) {
                if (resistance < 0)
                    cout << "Error: negative resistance" << endl;
                else
                    cout << "Error: too many arguments" << endl;
            } else {
                cout << "Error: invalid argument" << endl;
                ss.clear();
            }
        }

    }

}

void Parser::printR(string line){
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> command >> name;
        if (name == "all"){//print all resistors
          cout << "Print:"<< endl;
          for(int i=0;i<currentResistorSize;i++)
          arrayResistor[i].print();
            }
        else{
          if(nameNoExist(name))//print the selected resistor
          cout<<"Error: resistor "<<name<<" not found"<<endl;
          else
            cout << "Print:"<< endl;
            arrayResistor[getResistanceIndex(name)].print();
          }
    }
    if (numberOfWords(line) >= 3) {

        cout << "Error: too many arguments" << endl;
    }
}


void Parser::printNode(string line){
  trim(line);
    int nodeid = NULL;
    string s2;
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> command;
        getline(ss, s2);
        trim(s2);
        if (judgeTypeOfWord(s2) == 1) {
            stringstream ss(s2);
            ss >> nodeid;
            if (0 < nodeid && nodeid < maxNodeNumber){
                cout << "Print:"<< endl;
                arrayNode[nodeid].print();
              }
            else
                cout << "Error: node " << nodeid << " is out of permitted range 0-" <<maxNodeNumber<< endl;
        } else {
            getline(ss, s2);
            trim(s2);
            stringstream ss(s2);
            ss>>name;
            if (name == "all"){
                cout << "Print:" << endl;
                for(int i=0;i<maxNodeNumber;i++)//need a function to indicate the exact size of currentNodeSize
                arrayNode[i].print();//and sort them based on their number
              }
            else
                cout << "Error: invalid argument" << endl;
        }
    }
    if (numberOfWords(line) >= 3) {
        stringstream ss(line);
        ss >> command;
        getline(ss, s2);
        trim(s2);
        if (judgeTypeOfWord(s2) == 1) {
            stringstream ss(s2);
            ss >> nodeid;
            if (0 <= nodeid && nodeid <= maxNodeNumber)
                cout << "Error: too many arguments" << endl;
            else
                cout << "Error: node " << nodeid << " is out of permitted range 0-" <<maxNodeNumber<< endl;
        } else {
            stringstream ss(s2);
            ss >> name;
            if (name == "all")
                cout << "Error: too many arguments" << endl;
            else
                cout << "Error: invalid argument" << endl;
        }
    }
}

void Parser::deleteR(string line){
  string name, command;
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> command >> name;
        if (name == "all"){
          delete []arrayResistor;
          Resistor *arrayResistor;
          arrayResistor= new Resistor[maxResistors];
          for(int i=0;i<maxNodeNumber;i++){
            arrayNode[i].update();
          }
            cout << "Deleted: all resistors" << endl;
          }
        else
            cout << "Error: invalid arguments" << name << endl;
    }
    if (numberOfWords(line) >= 3) {
        cout << "Error: too many arguments" << endl;
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
int Rparser::judgeTypeOfWord(string line) {
    string restOfString;
    int intType;
    double doubleType;
    char charType;
    trim(line);
    stringstream ss(line);
    ss >> intType;
    bool intFlag = ss.fail();
    getline(ss, restOfString);
    if (!intFlag && (numberOfWords(restOfString) != numberOfWords(line))) {
        return 1;
    } else {
        ss.clear();
        stringstream ss(line);
        ss >> doubleType;
        bool doubleFlag = ss.fail();
        getline(ss, restOfString);
        if (!doubleFlag && numberOfWords(restOfString) != numberOfWords(line)) {
            return 2;
        } else {
            ss.clear();
            stringstream ss(line);
            ss >> charType;
            bool charFlag = ss.fail();
            getline(ss, restOfString);
            if (!charFlag && numberOfWords(restOfString) != numberOfWords(line))
                return 3;
            else
                return 4;
        }
    }

}

int Rparser::getResistanceIndex(string name){

  for(int i=0;i<currentResistorSize;i++){
    if(name==arrayResistor[i].getName())
    return i;
  }
}


bool Rparser::nameNoExist(string name){
  for(int i=0;i<currentResistorSize;i++){
    if(name==arrayResistor[i].getName())
    return false;
    else
    return true;
  }
}
void Rparser::trim(string & s) {
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);
    p = s.find_last_not_of(" /t");
    if (string::npos != p)
        s.erase(p + 1);
}
