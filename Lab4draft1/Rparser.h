/*
* File:   Rparser.h
* Author: yangjiaw
*
* Created on November 8, 2016, 2:18 PM
*/
#include<iostream>
#include<string>
#include<sstream>
#include"NodeList.h"


#ifndef RPARSER_H
#define	RPARSER_H
using namespace std;
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
	void solve(string line);
private:
	string line, command, name;
	int nodeid1, nodeid2;
	double resistance;
	double voltage;
	NodeList nodeList;
};

#endif	/* RPARSER_H */

