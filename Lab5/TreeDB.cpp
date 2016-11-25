#include "TreeDB.h"

TreeDB::TreeDB() {
	root = NULL;
	probesCount = 0;
}

bool TreeDB::insert(DBentry *newEntry) {
	if (root == NULL) {
		root = new TreeNode(newEntry);
	}
	else {
		
		TreeNode * temp = new TreeNode(newEntry);
		TreeNode* current = root;
		TreeNode* previous= root;
		bool onLeft;
		while (current!= NULL) {
			if (nameSame(temp->getEntry()->getName(), current->getEntry()->getName()))
			{
				delete newEntry;
				return false;
			}
			else {
				if (frontOneBigger(temp->getEntry()->getName(), current->getEntry()->getName()))
				{
					previous = current;
					current = current->getRight();
					onLeft = false;
				}
				else
				{
					previous = current;
					current = current->getLeft();
					onLeft = true;
				}
			}
		}
		if (onLeft)
			previous->setLeft(temp);
		else
			previous->setRight(temp);
	}
	return true;
}

DBentry* TreeDB::find(string name) {
	DBentry *currentEntry = NULL;
	TreeNode* current = root;
	bool findit = false;
	probesCount = 0;
	while ((current!= NULL) && !findit) {
		if (nameSame(name, current->getEntry()->getName())) {
			probesCount++;
			currentEntry = current->getEntry();
			findit = true;
		}
		else {
			if (frontOneBigger(name, current->getEntry()->getName()))
			{
				probesCount++;
				current = current->getRight();
			}
			else
			{
				probesCount++;
				current = current->getLeft();
			}
		}
	}
	return currentEntry;
}
void TreeDB::clear() {
	clear(root);
	root = NULL;
}
void TreeDB::clear(TreeNode *root) {
	if (root != NULL) {
		clear(root->getLeft());
		clear(root->getRight());
		delete root;
	}
	else
		return;
}

bool TreeDB::remove(string name) {
	TreeNode* parentNode = NULL;
	TreeNode* shouldMoved = root;
	TreeNode*newNodeAtThatPosition = root;
	bool shouldMoveAtLeft;
	if (findit(name)) {
		while (!nameSame(shouldMoved->getEntry()->getName(), name)) {
			if (frontOneBigger(name, shouldMoved->getEntry()->getName())) {//if the name is bigger, go right
				parentNode = shouldMoved;
				shouldMoved = shouldMoved->getRight();
				newNodeAtThatPosition = newNodeAtThatPosition->getRight();
				shouldMoveAtLeft = false;
			}
			else if (!frontOneBigger(name, shouldMoved->getEntry()->getName()))// name smaller, go left
			{
				parentNode = shouldMoved;
				shouldMoved = shouldMoved->getLeft();
				newNodeAtThatPosition = newNodeAtThatPosition->getLeft();
				shouldMoveAtLeft = true;
			}
		}// untill now we already have shouldMove reached the right place 
		 //and parentNode is that's parent
		// newNodeAtThatPosition still need to be found
		if ((shouldMoved->getLeft() == NULL) &&
			(shouldMoved->getRight() == NULL))
		{                                           //CASE 1:  if shouldMove has no child
			if (shouldMoveAtLeft)
			{
				parentNode->setLeft(NULL);
				newNodeAtThatPosition = NULL;
			}//should move on the left;
			else
			{
				parentNode->setRight(NULL);
				newNodeAtThatPosition = NULL;
			}//should move on the right
			delete shouldMoved;
		}
		else if ((shouldMoved->getLeft() != NULL) &&//CASE 2: shouldMoved only have left child
			(shouldMoved->getRight() == NULL)) {
			newNodeAtThatPosition = newNodeAtThatPosition->getLeft();
			if (shouldMoveAtLeft) {
				parentNode->setLeft(newNodeAtThatPosition);
			}
			else
				parentNode->setRight(newNodeAtThatPosition);
			delete shouldMoved;
		}

		/*//TreeNode*previous = NULL;
		while (newNodeAtThatPosition->getRight() != NULL)
		{
			parentOfNewNode = newNodeAtThatPosition;
			//previous = newNodeAtThatPosition;
			newNodeAtThatPosition = newNodeAtThatPosition->getRight();
		}//newNodeAtThatPosition already reaches the largest one that smaller than shouldMoved
		//and its partents get
		parentOfNewNode->setRight(NULL);
		TreeNode *lefestOneOfSubTree = newNodeAtThatPosition;
		while (lefestOneOfSubTree != NULL)
		{
			lefestOneOfSubTree = lefestOneOfSubTree->getLeft();
		}//lefestOneOfSubTree found;
		if (shouldMoveAtLeft) {
			parentNode->setLeft(newNodeAtThatPosition);
			if(lefestOneOfSubTree!=NULL)
			lefestOneOfSubTree->setLeft(leftChildOfShouldMoved);
		}
		else
		{
			parentNode->setRight(newNodeAtThatPosition);
			lefestOneOfSubTree->setLeft(leftChildOfShouldMoved);
		}

		delete shouldMoved;
	}*/
		else if ((shouldMoved->getLeft() == NULL) &&//CASE 3: shouldMoved only have right child
			(shouldMoved->getRight() != NULL)) {
			newNodeAtThatPosition = newNodeAtThatPosition->getRight();
			TreeNode*rightChildOfShouldMoved = newNodeAtThatPosition->getRight();
			if (shouldMoveAtLeft) {
				parentNode->setLeft(newNodeAtThatPosition);
			}
			else
				parentNode->setRight(newNodeAtThatPosition);
			delete shouldMoved;
		}
		/*TreeNode*parentOfNewNode = NULL;
		while (newNodeAtThatPosition != NULL)
		{
			parentOfNewNode = newNodeAtThatPosition;
			newNodeAtThatPosition = newNodeAtThatPosition->getRight();
		}//newNodeAtThatPosition already reaches the largest one that smaller than shouldMoved
		parentOfNewNode->setRight(NULL);
		TreeNode *lefestOneOfSubTree = newNodeAtThatPosition;
		while (lefestOneOfSubTree != NULL)
		{
			lefestOneOfSubTree = lefestOneOfSubTree->getLeft();
		}//lefestOneOfSubTree found;
		if (shouldMoveAtLeft) {
			parentNode->setLeft(newNodeAtThatPosition);
			lefestOneOfSubTree->setLeft(rightChildOfShouldMoved);
		}
		else
		{
			parentNode->setLeft(newNodeAtThatPosition);
			lefestOneOfSubTree->setLeft(rightChildOfShouldMoved);
		}
		delete shouldMoved;
	}*/
		else if ((shouldMoved->getLeft() != NULL) &&//CASE 4: shouldMoved have children on both sides
			(shouldMoved->getRight() != NULL)) {
			TreeNode*parentOfNewNode = newNodeAtThatPosition;
			TreeNode*leftChildOfShouldMoved = newNodeAtThatPosition->getLeft();
			TreeNode*rightChildOfShouldMoved = newNodeAtThatPosition->getRight();
			newNodeAtThatPosition = newNodeAtThatPosition->getLeft();
			if (newNodeAtThatPosition->getRight() == NULL) {//leftChild of should move has no right child
				if (shouldMoveAtLeft)
					parentNode->setLeft(newNodeAtThatPosition);
				else
					parentNode->setRight(newNodeAtThatPosition);
				newNodeAtThatPosition->setRight(rightChildOfShouldMoved);
				delete shouldMoved;
			}
			else if (newNodeAtThatPosition->getRight() != NULL) {//leftChild of shouldMoved has right child;
				while (newNodeAtThatPosition->getRight() != NULL) {//move to the rightest one
					parentOfNewNode = newNodeAtThatPosition;
					newNodeAtThatPosition = newNodeAtThatPosition->getRight();
				}
				if (newNodeAtThatPosition->getLeft() == NULL) {
					if (shouldMoveAtLeft)
						parentNode->setLeft(newNodeAtThatPosition);
					else
						parentNode->setRight(newNodeAtThatPosition);
					newNodeAtThatPosition->setLeft(leftChildOfShouldMoved);
					delete shouldMoved;
				}
				else if (newNodeAtThatPosition->getLeft() != NULL) {
					TreeNode *leftsubtree = newNodeAtThatPosition->getLeft();
					parentOfNewNode->setRight(leftsubtree);
					if (shouldMoveAtLeft)
						parentNode->setLeft(newNodeAtThatPosition);
					else
						parentNode->setRight(newNodeAtThatPosition);
					newNodeAtThatPosition->setLeft(leftChildOfShouldMoved);
				}



			}
			/*while (newNodeAtThatPosition->getRight() != NULL)
			{
				parentOfNewNode = newNodeAtThatPosition;
				newNodeAtThatPosition = newNodeAtThatPosition->getRight();
			}//newNodeAtThatPosition already reaches the largest one that smaller than shouldMoved


			if (leftChildOfShouldMoved->getRight() != NULL) {
				TreeNode*lefestOneOfSubTree2 = leftChildOfShouldMoved->getRight();
				while (lefestOneOfSubTree2->getLeft()!=NULL)
			{
				lefestOneOfSubTree2 = lefestOneOfSubTree2->getLeft();
			}

			if (shouldMoveAtLeft) {
				parentNode->setLeft(newNodeAtThatPosition);
				newNodeAtThatPosition->setLeft(rightChildOfShouldMoved);
				lefestOneOfSubTree2->setLeft(leftChildOfShouldMoved);
			}
			else
			{
				parentNode->setRight(newNodeAtThatPosition);
				newNodeAtThatPosition->setLeft(rightChildOfShouldMoved);
				lefestOneOfSubTree2->setLeft(leftChildOfShouldMoved);
			}
			delete shouldMoved;
		}*/

			return true;

		}
	}

else//could'd not find the specific entry with that name
		return false;
}
void TreeDB::printProbes() const {
	cout << probesCount;
}


void TreeDB::countActive() const {
	TreeNode *temp = root;
	int count = countactive(root);
	cout << count << endl;
}

int TreeDB::countactive(TreeNode *a) const {
	int count = 0;
	if (a != NULL) {
		count = count + countactive(a->getLeft());
		if (a->getEntry()->getActive())
			count++;
		count = count + countactive(a->getRight());
	}
	else
		return 0;
	return count;
}
void TreeDB::printall(TreeNode*a) {
	if (a != NULL) {
		printall(a->getLeft());
		cout << *a->getEntry();
		printall(a->getRight());
	}
	else
		return;
}
void TreeDB::printAll() {
	printall(root);
}

TreeNode *TreeDB::returnRoot() {
	return root;
}

TreeDB::~TreeDB() {
	clear(root);
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

bool TreeDB::findit(string name) {
	DBentry *currentEntry = NULL;
	TreeNode* current = root;
	while (current->getEntry() != NULL) {
		if (nameSame(name, current->getEntry()->getName()))
			return true;
		else {
			if (frontOneBigger(name, current->getEntry()->getName()))
				current = current->getRight();
			else
				current = current->getLeft();
		}
	}
	return false;
}
