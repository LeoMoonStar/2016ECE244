#include "TreeDB.h"

TreeDB::TreeDB() {
    root = NULL;
    probesCount = 0;
}

bool TreeDB::insert(DBentry *newEntry) {
    if (root == NULL) {
        TreeNode newNode(newEntry);
        root = &newNode;
    } else {
        TreeNode * temp(newEntry);
        TreeNode* current = root;
        while (current->getEntry()->getName() != NULL) {
            if (nameSame(temp->getEntry()->getName(), current->getEntry()->getName()))
                return false;
            else {
                if (frontOneBigger(temp->getEntry()->getName(), current->getEntry()->getName()))
                    current = current->getRight();
                else 
                    current =current->getLeft();
        }
    }
        current=temp;
        return true;
}
}

DBentry TreeDB::find(string name) {
    DBentry *currentEntry;
    TreeNode* current=root;
    while(current->getEntry()->getName() != NULL){
        if (nameSame(name, current->getEntry()->getName()))
                currentEntry=current->getEntry();
            else {
                if (frontOneBigger(name, current->getEntry()->getName()))
                    current = current->getRight();
                else 
                    current=current->getLeft();
            }
    }
    return currentEntry;
}
void TreeDB::clear(){
    
}
void TreeDB::printProbes(){
    
}
void TreeDB::countActive() const{
    
}
ostream&operator<<(ostream& out, const TreeDB& rhs){
    
}

TreeNode *TreeDB::returnRoot() {
    return root;
}

int TreeDB::getprobes() {
    return probesCount;
}



TreeDB::~TreeDB() {
    TreeNode *current = root;
    while (current->getLeft() != NULL) {

    }
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

bool nameSame(string a, string b) {
    if (a == b)
        return true;
    else
        return false;
}

bool TreeDB::findit(string name){
    DBentry *currentEntry;
    TreeNode* current=root;
    while(current->getEntry()->getName() != NULL){
        if (nameSame(name, current->getEntry()->getName()))
                return true;
            else {
                if (frontOneBigger(name, current->getEntry()->getName()))
                    current = current->getRight();
                else 
                    current=current->getLeft();
            }
    }
    return false;
}
