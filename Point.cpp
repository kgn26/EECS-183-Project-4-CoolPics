/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * Contains the methods for class Point
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"


int Point::checkRange(int val) {
    if (val < 0) {
        return 0;
    } else if (val >= DIMENSION) {
        return DIMENSION - 1;
    } else {
        return val;
    }
}

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int val) {
    x = checkRange(val);
    return;
}

void Point::setY(int val) {
    y = checkRange(val);
    return;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

void  Point::read(istream& ins) {
    int xVal;
    int yVal;
    char junk;
    
    ins >> junk >> xVal >> junk >> yVal >> junk;
    x = checkRange(xVal);
    y = checkRange(yVal);
    
    return;
}

void Point::write(ostream& outs) {
    outs << "(" << x << "," << y << ")";
    return;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
