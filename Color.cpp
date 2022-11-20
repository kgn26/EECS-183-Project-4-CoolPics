/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * Contains the methods for class Color
 */

#include "Color.h"

int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    } else if (val > 255) {
        return 255;
    }
    
    return val;
}

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

void Color::setRed(int redVal) {
    red = checkRange(redVal);
    return;
}

int Color::getRed() {
    return red;
}

void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
    return;
}

int Color::getGreen() {
    return green;
}

void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
    return;
}

int Color::getBlue() {
    return blue;
}

void Color::read(istream& ins) {
    int redVal, greenVal, blueVal;
    ins >> redVal >> greenVal >> blueVal;
    
    setRed(redVal);
    setGreen(greenVal);
    setBlue(blueVal);
    
    return;
}

void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
    return;
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
