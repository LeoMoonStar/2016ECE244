#include "TreeDB.h"



TreeDB::TreeDB()
{
	root = NULL;
	probesCount = 0;
}

bool TreeDB::insert(DBentry *newEntry) {
	if (root == NULL)
		root->getEntry()->

}

DBentry TreeDB::find(string name) {

}




TreeDB::~TreeDB()
{  
	TreeNode *current = root;
	while(current->getLeft() != NULL)
	{

	}
}

