/* 
 * File:   Resistor.h
 * Author: yangjiaw
 *
 * Created on November 8, 2016, 2:17 PM
 */

#ifndef RESISTOR_H
#define	RESISTOR_H
const int MAX_LABLE_LENGTH=100;
class Resistor {
public:
    Resistor();
  
    ~Resistor();
private:
    char lable[MAX_LABLE_LENGTH];
    int endpoints[2];
};

#endif	/* RESISTOR_H */

