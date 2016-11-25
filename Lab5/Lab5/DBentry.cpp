#include "DBentry.h"

DBentry::DBentry() {
	name = "";
	IPaddress = 0;
	active = false;
}

DBentry::DBentry(DBentry* newEntry) {
	name = newEntry->getName();
	IPaddress = newEntry->getIPaddress();
	active = newEntry->getActive();
}

DBentry::DBentry(string _name, unsigned int _IPaddress, bool _active) {
	name = _name;
	IPaddress = _IPaddress;
	active = _active;
}

unsigned int DBentry::getIPaddress() const {
	return IPaddress;
}

bool DBentry::getActive() const {
	return active;
}

void DBentry::setName(string _name) {
	name = _name;
}

void DBentry::setActive(bool _active) {
	active = _active;
}

void DBentry::setIPaddress(unsigned int _IPaddress) {
	IPaddress = _IPaddress;
}

string DBentry::getName() const {
	return name;
}

DBentry::~DBentry() {
}

ostream & operator<<(ostream &out, const DBentry&rhs) {
	out << rhs.getName() << " : " << rhs.getIPaddress() << " : ";
	if (rhs.getActive())
		out << "active" << endl;
	else
		out << "inactive" << endl;
	return out;
}

