/* 
 * File:   Rparser.cpp
 * Author: yangjiaw
 * 
 * Created on November 8, 2016, 2:18 PM
 */

#include "Rparser.h"

Rparser::Rparser() {
}

Rparser::~Rparser() {
}
void Rparser::parser(){
    while(!cin.eof()){
        cout<<"> ";
        getline(cin,line);
        functionSelect(line);
        }
    
}

void Rparser::functionSelect(string line){
stringline ss(line);
ss>>command;
switch(command){
    case "insertR":
        insertR(line);
        break;
    case "modifyR":
        modifyR(line);
        break;
    case "setV":
        setV(line);
        break;
    case "unsetV":
        unsetV(line);
        break;
    case "solve":
        solve(line);
        break;
    case"deleteR":
        delet(line);
        break;
    case "printR":
        printR(line);
        break;
    case "printNode":
        printNode(line);
        break;
    default:
        std::cout<<"Error: invalid command"<<std::endl;
}
}

void Rparse::insertR(string line){
    
}
void Rparse::modifyR(string line){
    
}
void Rparse::setV(string line){
    stringstream ss(line);
    ss>>command>>nodeid>>voltage;
    
    
}
void Rparse::unsetV(string line){
    
}
void Rparse::delet(string line){
    
}
void Rparse::printR(string line){
    
}
void Rparse::printNode(string line){
    
}




