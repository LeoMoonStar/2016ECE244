

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Rparser.h"

using namespace std;
Resistor *arrayResistor = NULL;//Global Resistor array initialized to NULL
Node *arrayNode = NULL;//Global Node array initialized to NULL
// Constructor: to define the default values
Parser::Parser()
{
    resistorIndex=0;
    maxNodeNumber=0;
    maxResistors=0;
    newMaxNode =0;
}

void Rparser()
{
    Parser p;
    // Stores entire input line
    string line;
    cout<<"> ";
    // Get a line from the input stream
    getline(cin,line);
    // Runs until an End of File (EOF) command is entered
    while(!cin.eof())
    {
        p.input(line);
        cout<<"> ";
        getline(cin,line);

    }
    delete []arrayResistor; // deletes resistor array
    delete []arrayNode; // deletes node array
}
bool Parser::input(string word)
{
    // Counts the number of letters in a string
    for(int i =0; word[i]!='\0'; i++)
        letters++;

    // Copies the string into a new string called 'line'
    size_t length = word.copy(line,letters,0);
    line[length]='\0';
    //adds a null character at the end of the string

    stringstream ss(line);
    ss>>command;
//calls function insertR when the command is insertR
    if(command == "insertR")
    {
        insertR(line);
        return true;
    }
    //calls function modifyR when the command is modifyR
    else if(command == "modifyR")
    {
        modifyR(line);
        return true;
    }
//calls function printR when the command is printR
    else if(command == "printR")
    {
        printR(line);
        return true;
    }
//calls function printNode when the command is printNode
    else if(command == "printNode")
    {
        printNode(line);
        return true;
    }
//calls function deleteR when the command is deleteR
    else if(command == "deleteR")
    {
        deleteR(line);
        return true;
    }
//calls function maxVal when the command is maxVal
    else if(command == "maxVal")
    {
        maxVal(line);
        return true;
    }
    else
    //gives an error when the command entered is not valid
    {
        cout<<"Error: invalid command"<<endl;
        return false;
    }
}

void Parser::insertR(string line)
{
   

    stringstream ss(line); //makes a new stringstream as ss
    ss>>command>>name>>resistance>>node1>>node2;//the first string is command
    if((node1 >maxNodeNumber)||(node1<0))
    {
        cout<<"Error: node "<<node1<<" is out of permitted range "<<"0-"<<maxNodeNumber<<endl;
        
    }
    else if((node2 >maxNodeNumber)||(node2<0))
    {
        cout<<"Error: node "<<node2<<" is out of permitted range "<<"0-"<<maxNodeNumber<<endl;
        
    }
    else if(node1 == node2)
            {
                cout<<"Error: both terminals of resistor connect to node "<<node1<<endl;
                
            }
    else if(resistorIndex == maxResistors)
    {
        cout<<"Error: resistor array is full"<<endl;
        
    }
    else if(arrayNode[node1].canAddResistor(resistorIndex) && arrayNode[node2].canAddResistor(resistorIndex))
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        int *nodes; //makes a node array
        nodes = new int;
        nodes[0] = node1;
        nodes[1] = node2;
        Resistor temp (resistorIndex,name,resistance,nodes); // declares an object temp that passes all the values
        arrayResistor[resistorIndex] = temp; // stores that value in the array
        arrayNode[node1].Resnum(); //updates the counter when a specific node number is called
        arrayNode[node2].Resnum();
        resistorIndex++;
        cout<<"Inserted: resistor "<<name <<" "<<resistance <<" Ohms "<< node1 <<" -> "<<node2<<endl;
        delete nodes; // deletes the node array
    }
}

void Parser::modifyR(string line)
{
    //checks for the arguments, when command is modifyR
    bool found=false;
    stringstream ss(line);
    ss>>command;
    ss>>name;
    ss>>resistance;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    for(int i =0; i<resistorIndex; i++)
    {
        
        if(arrayResistor[i].getName() == name)
        {
            found=true;
            cout<<"Modified: resistor "<<name<<" from "<<arrayResistor[i].getResistance()<<" Ohms ";
            arrayResistor[i].setResistance(resistance);
            cout<<"to "<<resistance<<" Ohms"<<endl;
           
        }

    }
    if(!found)
        cout<<"Error: resistor "<<name<<" not found"<<endl;
}

void Parser::printR(string line)
{
    //checks for the arguments, when command is printR
    int i;
    
    stringstream ss(line);
    ss>>command>>name;
    
    if(name=="all")
    {
        cout<<"Print: "<<endl; //prints all the resistors
        for(i =0; i<resistorIndex; i++)
        {

            arrayResistor[i].print();

        }
    }
    else
    {
        bool found=false;
        for(i =0; i<resistorIndex; i++)
        {
            if(arrayResistor[i].getName() == name)
            {
                cout<<"Print: "<<endl; // prints a specific resistor
                arrayResistor[i].print();
                found=true;
            }

        }
        if(!found)
            cout<<"Error: resistor "<<name<<" not found"<<endl;
    }
}

void Parser::deleteR(string line)
{
    //checks for the arguments, when command is deleteR
    
    stringstream ss(line);
    ss>>command;
    ss>>name;
    if(name=="all")
    {
        // initializes everything to zero
        int i;
        Node delN;


        Resistor del;
        for(i=0; i<newMaxNode; i++)
        {
            arrayNode[i].deleteN();
        }
        delN.deleteN();
        del.deleteR();
       
        resistorIndex = 0;
        cout<<"Deleted: all resistors"<<endl;

    }
}

void Parser::printNode(string line)
{
    stringstream ss(line);
    ss>>command;
    ss>>name;

    if(name== "all")
    {
        cout<<"Print: "<<endl;
            for(int i=0; i<newMaxNode; i++)
            {
                arrayNode[i].print(i);
            }
    }
        else{
            stringstream ss(line);
            ss>>command>>node1;
            if(maxNodeNumber ==0)
                {
                    cout<<"Print: "<<endl;
                 
                }
                else
                {
                    //prints a specific node
                    cout<<"Print: "<<endl;
                    arrayNode[node1].print(node1);
                    
                }
        }
}


void Parser::maxVal(string line)
{
    stringstream ss(line);
  ss>>command>>maxNodeNumber>>maxResistors;
  if((maxNodeNumber>0)&&(maxResistors>0)){
      delete []arrayResistor; // deletes resistor array
      delete []arrayNode; // deletes node array
      resistorIndex=0;
    arrayResistor = new Resistor [maxResistors];//initializes array of size max resistors
    newMaxNode = maxNodeNumber + 1;
    arrayNode = new Node[newMaxNode];

    cout<<"New network: max node number is "<<maxNodeNumber << "; max resistors is "<<maxResistors <<endl;}
  else if((maxNodeNumber<=0)||(maxResistors<=0))
      cout<<"Error: maxVal arguments must be greater than 0"<<endl;
 
}


