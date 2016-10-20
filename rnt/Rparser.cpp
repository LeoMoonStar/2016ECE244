#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include"Node"
#include"Resistor"
using namespace std;

void Rparser::Rparser(){
bool maxValGet=false;
while(!maxValGet){
  cout<<"> ";
  getline(cin,line);
  stringstream ss(line);
  ss>>command>>maxNodeNumber>>maxResistors;
  if(command=="maxVal"){
    if((maxNodeNumber>0)&&(maxResistors>0))
      maxValGet=true;
      else
      cout<<"Error: maxVal argument must be greater than 0"<<endl;
    }
  }
  while(!cin.eof()){
          cout<<"> ";
          getline(cin,line);
          functionSelect(line);
        }
      }

void Rparser::functionSelect(string line){
stringstream ss(line);


}
