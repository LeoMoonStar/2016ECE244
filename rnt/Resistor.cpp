#ifndef RPARSER_H
#define  RPARSER_H
#endif

#include <string>
#include <iostream>
#include"Node"
#include"Resistor"

Resistor::Resistor(){
  resistance=0;
  for(int i=0;i<2;i++)
  endpointNodeIDs[i]=0;
  name="";
}

Resistor::Resistor(int rIndex_,string name_,double resistance_,int endpoints_[2]){
  name=name_;
  resistance=resistance_;
  for(int i=0;i<2;i++)
  endpointNodeIDs[i]=endpoints_[i];
}

Resistor::~Resistor(){

}
void Resistor::print(){
  operator<<(ostrem&,const Resistor&);
}

string Resistor::getName() const {
  return name;
}

double Resistor::getResistance(){
  return resistance;
}

void Resistor::setResistance(double resistance_){

}
