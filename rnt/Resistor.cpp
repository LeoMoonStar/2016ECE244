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
cout<<setfill(' ')<<setw(20);
cout<<left<<name;
cout<<' ';
cout<<setfill(' ')<<setw(8);
cout<<right<<resistance;
cout<<' '<<"Oms "<<endpointNodeIDs[0]<<" -> "<<endpointNodeIDs[1]<<endl;
}

string Resistor::getName() const {
  return name;
}

double Resistor::getResistance(){
  return resistance;
}

void Resistor::setName(string name){
  name=name;
}
void Resistor::setEndPoint(int nodeid1,int nodeid2){
  endpointNodeIDs[0]=noid1;
  endpointNodeIDs[1]=noid2;
}
int Resistor::getEndPoint1(){
  return endpointNodeIDs[0];
}
int Resistor::getEndPoint2(){
    return endpointNodeIDs[1];
}
void Resistor::setResistance(double resistance_){
resistance=resistance;
}
