/* 
 * File:   NodeList.h
 * Author: yangjiaw
 *
 * Created on November 8, 2016, 2:18 PM
 */
#include "Node.h"
#ifndef NODELIST_H
#define	NODELIST_H

class NodeList {
public:
    NodeList();
    ~NodeList();
private:
    Node node;
    ResistorList rList;
    Node* next;
};

#endif	/* NODELIST_H */

