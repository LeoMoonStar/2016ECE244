#ifndef NODE_H
#define NODE_H

#include<iomanip>
#include<iostream>
#include<string>
#include<sstream>
#include<stringstream>
#include"Node"
using namespace std;
#define MAX_RESISTORS_PER_NODE 5
extern Resistor *arrayResistor;


Node::Node() {
  numRes=0;
  for(int i=0;i<MAX_RESISTORS_PER_NODE;i++)
  resIDArray[i]=0;
}
Node::~Node(){

}

bool Node::canAddResistor(int rIndex){
  if(numRes>=MAX_RESISTORS_PER_NODE){
cout<<"Error: node is full"<<endl;
  return false;
}
  else{
    resIDArray[numRes]=rIndex;
    numRes++;
    return true;
  }
}

void Node::print(int nodeIndex){
  cout<<"Print:"<<endl;
  cout<<"Connection at node "<<nodeIndex<<": "<<numRes<<" resistor(s)"<<endl;
for(int i=0;i<numRes;i++){
  cout<<setfill(2)<<arrayResistor[resIDArray[i].name]
}
}


#endif
