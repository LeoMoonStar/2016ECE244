/* 
 * File:   Node.h
 * Author: yangjiaw
 *
 * Created on November 8, 2016, 2:17 PM
 */
#include "ResistorList.h"
#ifndef NODE_H
#define	NODE_H

class Node {
public:
    Node();
    int getId();
    double getVoltage();
    void setId(int id);
    void setVoltage(double v);
    ~Node();
private:
    int NodeId;
    double voltage;
};

#endif	/* NODE_H */

