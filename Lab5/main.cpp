
#include"DBentry.h"
#include"TreeDB.h"
#include"TreeNode.h"
#include<sstream>
using namespace std;

void functionSelect(string line,TreeDB *a);
bool frontOneBigger(string a, string b);
bool insert(string line, TreeDB *a);
bool find(string line, TreeDB *a);
bool remove(string line, TreeDB *a);
bool printall(TreeDB *a);
bool printprobes(string line, TreeDB *a);
bool removeall(TreeDB *a);
bool countactive(TreeDB *a);
bool updatestatus(string line, TreeDB *a);



int main() {
	TreeDB tdb;
	TreeDB* a = &tdb;
	string line;
	cout << "> ";
	getline(cin, line);
	while (!cin.eof) {
		functionSelect(line);
		cout << "> ";
		getline(cin, line);
	}
	

	return 0;
}



void functionSelect(string line,TreeDB *a) {
	string command;
	stringstream ss(line);
	ss >> command;
	if (command == "insert")
		insert(line,a);
	else if (command == "find")
		find(line,a);
	else if (command == "remove")
		remove(line,a);
	else if (command == "printall")
		printall(a);
	else if (command == "printprobes")
		printprobes(line,a);
	else if (command == "removeall")
		removeall(a);
	else if (command == "countactive")
		countactive(a);
	else if (command == "updatestatus")
		updatestatus(line,a);
	else
		cout << "Invalid command" << endl;
}

bool insert(string line, TreeDB *a) {
	string command, name;
	int ipAddress;
	bool status;
	stringstream ss(line);
	ss >> command >> name >> ipAddress >> status;

}
bool find(string line, TreeDB *a) {
	string command, name;
	stringstream ss(line);
	ss >> command >> name;
}
bool remove(string line, TreeDB *a) {
	string command, name;
	stringstream ss(line);
	ss >> command >> name;
}
bool printall(TreeDB *a) {

}
bool printprobes(string line, TreeDB *a) {

}
bool removeall(TreeDB *a) {

}
bool countactive(TreeDB *a) {

}
bool updatestatus(string line, TreeDB *a) {

}




bool frontOneBigger(string a, string b) {
	int size_a = a.size();
	int size_b = b.size();
	int count = 0;
	bool frontBigger = true;
	while ((count <= size_a) && (count <= size_b) && frontBigger) {
		if (a[count] < b[count])
			frontBigger = false;
		else if (a[count] == b[count])
			count++;
		else
			return frontBigger;
	}
	return frontBigger;
}