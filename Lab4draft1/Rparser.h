/* 
 * File:   Rparser.h
 * Author: yangjiaw
 *
 * Created on November 8, 2016, 2:18 PM
 */
#include<iostream>
#include<sstream>
#include<string>

#ifndef RPARSER_H
#define	RPARSER_H

class Rparser {
public:
    Rparser();//CONSTRUCTOR
    ~Rparser();//DECONSTRUCTOR
    void parser();
    void functionSelect(string line);
    void insertR(string line);
    void modifyR(string line);
    void setV(string line);
    void unsetV(string line);
    void delet(string line);
    void printR(string line);
    void printNode(string line);
    int numberOfWords(string line);
private:
    string line,command,name;
    int nodeid;
    double voltage;
    

};

#endif	/* RPARSER_H */

