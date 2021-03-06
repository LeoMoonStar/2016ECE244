
#include"DBentry.h"
#include"TreeDB.h"
#include"TreeNode.h"
#include<sstream>
using namespace std;

void functionSelect(string line, TreeDB *a);
bool frontOneBigger(string a, string b);
void insert(string line, TreeDB *a);
void find(string line, TreeDB *a);
void remove(string line, TreeDB *a);
void printall(TreeDB *a);
void printprobes(string line, TreeDB *a);
void removeall(TreeDB *a);
void countactive(TreeDB *a);
void updatestatus(string line, TreeDB *a);

int main() {
	TreeDB tdb;
	TreeDB *a = new TreeDB(tdb);
	string line;
	cout << "> ";
	getline(cin, line);
	while (!cin.eof()) {
		functionSelect(line,a);
		cout << "> ";
		getline(cin, line);
	}


	return 0;
}

void functionSelect(string line, TreeDB *a) {
	string command;
	stringstream ss(line);
	ss >> command;
	if (command == "insert")
		insert(line, a);
	else if (command == "find")
		find(line, a);
	else if (command == "remove")
		remove(line, a);
	else if (command == "printall")
		printall(a);
	else if (command == "printprobes")
		printprobes(line, a);
	else if (command == "removeall")
		removeall(a);
	else if (command == "countactive")
		countactive(a);
	else if (command == "updatestatus")
		updatestatus(line, a);
	else
		cout << "Invalid command" << endl;
}

void insert(string line, TreeDB *a) {//done
	string command, name;
	unsigned int ipAddress;
	string sss;
	bool status;
	stringstream ss(line);
	ss >> command >> name >> ipAddress >> sss;
	if (sss == "active")
		status = true;
	else
		status = false;
	DBentry *newEntry=new DBentry(name, ipAddress, status);
	if (a->insert(newEntry))
		cout << "Success" << endl;

	else {
		delete newEntry;
		cout << "Error: entry already exists" << endl;
	}
}

void find(string line, TreeDB *a) {//done
	string command, name;
	stringstream ss(line);
	ss >> command >> name;
	if (a->findit(name)) {
		DBentry findEntry(a->find(name));
		cout << findEntry ;
	}
	else
		cout << "Error: entry does not exist" << endl;
}

void remove(string line, TreeDB *a) {
	string command, name;
	stringstream ss(line);
	ss >> command >> name;
	if (a->remove(name))
		cout << "Success" << endl;
	else
		cout << "Error: entry does not exist" << endl;
}

void printall(TreeDB *a) {//done
	a->printAll();
}

void printprobes(string line, TreeDB *a) {//  done
	string command, name;
	stringstream ss(line);
	ss >> command >> name;
	if (a->findit(name)) {
		DBentry findEntry(a->find(name));
		a->printProbes();
		cout << " " << name << endl;
	}
	else
		cout << "Error: entry does not exist" << endl;
}

void removeall(TreeDB *a) {//done
	a->clear();
	cout << "Success" << endl;

}

void countactive(TreeDB *a) {//dont
	a->countActive();
}

void updatestatus(string line, TreeDB *a) {//done
	string command, name, sss;
	bool status;
	stringstream ss(line);
	ss >> command >> name >> sss;
	if (sss == "active")
		status = true;
	else
		status = false;
	if (a->findit(name)) {
		DBentry *findOne = a->find(name);
		findOne->setActive(status);
		cout << "Success" << endl;
	}
	else
		cout << "Error: entry does not exist" << endl;
}

