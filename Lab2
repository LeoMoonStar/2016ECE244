// lab2_2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
using namespace std;

void insert(string line);
void modify(string line);
void print(string line);
void printNode(string line);
void deleteFunction(string line);
int numberOfWords(string line);
int judgeTypeOfWord(string line);
void trim(string& s);

int main() {
    string line;
    cout << "> ";
    getline(cin, line);
    while (!cin.eof()) {
        string command;
        stringstream ss(line);
        ss >> command;
        if (command == "insertR")
            insert(line);
        else if (command == "modifyR")
            modify(line);
        else if (command == "printR")
            print(line);
        else if (command == "printNode")
            printNode(line);
        else if (command == "deleteR")
            deleteFunction(line);
        else
            cout << "Error: invalid command" << endl;
        cout << "> ";
        getline(cin, line);
    }
    return 0;
}

void insert(string line) {
    string command, name, s2;
    double resistance;
    int nodeid1, nodeid2;
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

void modify(string line) {
    trim(line);
    string name, command;
    double resistance;
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
                else
                    cout << "Modified: resistor " << name << " to " << setprecision(2) << fixed << resistance << " Ohms" << endl;
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

void print(string line) {
    string name, command;
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> command >> name;
        if (name == "all")
            cout << "Print: all resistors" << endl;
        else
            cout << "Print: resistor " << name << endl;
    }
    if (numberOfWords(line) >= 3) {

        cout << "Error: too many arguments" << endl;
    }
}

void printNode(string line) {
    trim(line);
    int nodeid = NULL;
    string name, command, s2;
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
            if (0 < nodeid && nodeid < 5000)
                cout << "Print: node " << nodeid << endl;
            else
                cout << "Error: node " << nodeid << " is out of permitted range 0-5000" << endl;
        } else {
            getline(ss, s2);
            trim(s2);
            stringstream ss(s2);
            ss>>name;
            if (name == "all")
                cout << "Print: all nodes" << endl;
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
            if (0 <= nodeid && nodeid <= 5000)
                cout << "Error: too many arguments" << endl;
            else
                cout << "Error: node " << nodeid << " is out of permitted range 0-5000" << endl;
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

void deleteFunction(string line) {
    string name, command;
    if (numberOfWords(line) == 1)
        cout << "Error: too few arguments" << endl;
    if (numberOfWords(line) == 2) {
        stringstream ss(line);
        ss >> command >> name;
        if (name == "all")
            cout << "Deleted: all resistors" << endl;
        else
            cout << "Deleted: resistor " << name << endl;
    }
    if (numberOfWords(line) >= 3) {
        cout << "Error: too many arguments" << endl;
    }
}

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

int judgeTypeOfWord(string line) {
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

void trim(string & s) {
    size_t p = s.find_first_not_of(" \t");
    s.erase(0, p);
    p = s.find_last_not_of(" /t");
    if (string::npos != p)
        s.erase(p + 1);
}
