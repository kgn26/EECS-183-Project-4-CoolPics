/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * Contains functions for testing Shape classes.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();
    
    return;
}

void test_Point() {
    cout << "-----Testing Point-----" << endl;
    
    // test of default constructor
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
         << "," << p1.getY()
         << ")" << endl;
    
    cout << endl;
    
    return;
}

void test_Color() {
    cout << "-----Testing Color-----" << endl;
    
    // test of default constructor
    Color c1;
    cout << "Expected: 0 0 0, actual: " << c1 << endl;
    
    // test of the non-default constructor
    Color c2(120, 56, 250);
    cout << "Expected: 120 56 250, actual: " << c2 << endl;
    
    Color c3;
    // test of member function: setRed()
    c3.setRed(50);
    // test of member function: setGreen()
    c3.setGreen(30);
    // test of member function: setBlue()
    c3.setBlue(100);
    
    Color c4;
    // test of member function: setRed()
    c4.setRed(-50);
    // test of member function: setGreen()
    c4.setGreen(265);
    // test of member function: setBlue()
    c4.setBlue(-30);
    cout << "Expected: 0 255 0, actual: " << c4 << endl;

    // test of member functions getRed(), getGreen() and getBlue()
    cout << "Expected: 50 30 100, actual: ";
    cout << c3.getRed() << " "
         << c3.getGreen() << " "
         << c3.getBlue() << endl;
    
    cout << endl;

    return;
}

void test_Line() {
    cout << "-----Testing Line-----" << endl;
    
    Point start1(2, 4);
    Point end1(24, 56);
    Color lineColor1(45, 120, 255);
    
    // test of the non-default constructor
    Line l1(start1, end1, lineColor1);
    cout << "Expected: (2,4) (24,56) 45 120 255, actual: " << l1 << endl;
    
    // test of member function: setStart()
    Point start2(15, 16);
    l1.setStart(start2);
    // test of member function: setEnd()
    Point end2(78, 42);
    l1.setEnd(end2);
    // test of member function: setColor()
    Color lineColor2(78, 12, 45);
    l1.setColor(lineColor2);

    // test of member functions getStart(), getEnd() and getColor()
    cout << "Expected: (15,16) (78,42) 78 12 45, actual: ";
    cout << l1.getStart() << " "
         << l1.getEnd() << " "
         << l1.getColor() << endl;
    
    Line l2(start2, end2, lineColor2);
    ofstream outs;
    outs.open("data3.txt");
    l2.write(outs);
    outs.close();
    
    cout << endl;

    return;
}

void test_Triangle() {
    cout << "-----Testing Triangle-----" << endl;
    
    Point vertexOne(1, 0);
    Point vertexTwo(20, 45);
    Point vertexThree(50, 37);
    Color c1(255, 145, 220);
    Color c2(45, 255, 255);
    Color c3(90, 90, 90);
    
    // test of first non-default constructor
    Triangle t1(vertexOne, c1, vertexTwo, c2, vertexThree, c3);
    cout << "Expected: (1,0) 255 145 220 (20,45) 45 255 255 (50,37) 90 90 90, "
         << "actual: " << t1 << endl;
    
    // test of second non-default constructor
    Triangle t2(vertexOne, vertexTwo, vertexThree, c2);
    cout << "Expected: (1,0) 45 255 255 (20,45) 45 255 255 (50,37) 45 255 255, "
         << "actual: " << t2 << endl;
    
    Triangle t3;
    Point vertexFour(60, 60);
    Point vertexFive(25, 10);
    Point vertexSix(80, 77);
    Color c4(34, 111, 240);
    Color c5(124, 0, 78);
    Color c6(97, 134, 233);
    
    // test of setter functions
    t3.setVertexOne(vertexFour);
    t3.setVertexTwo(vertexFive);
    t3.setVertexThree(vertexSix);
    t3.setVertexOneColor(c4);
    t3.setVertexTwoColor(c5);
    t3.setVertexThreeColor(c6);

    // test of getter functions
    cout << "Expected: (60,60) 34 111 240 (25,10) 124 0 78 (80,77) 97 134 233, actual: ";
    cout << t3.getVertexOne() << " "
         << t3.getVertexOneColor() << " "
         << t3.getVertexTwo() << " "
         << t3.getVertexTwoColor() << " "
         << t3.getVertexThree() << " "
         << t3.getVertexThreeColor() << endl;
    
    // test of member functions: read() and write()
    Triangle t4;
    
    ifstream infile;
    infile.open("data1.txt");
    infile >> t4;
    cout << "Expected: (45,26) 230 22 187 (10,78) 67 35 127 (80,74) 64 52 27, actual: ";
    cout << t4 << endl;
    infile >> t4;
    cout << "Expected: (90,56) 255 240 120 (88,24) 255 240 120 (78,78) 255 240 120, actual: ";
    cout << t4 << endl;
    infile.close();
    
    cout << endl;
    
    return;
}

void test_Circle() {
    cout << "-----Testing Circle-----" << endl;
    
    Point center1(2, 4);
    int radius1 = 24;
    Color color1(45, 120, 255);
    
    // test of the non-default constructor
    Circle c1(center1, radius1, color1);
    cout << "Expected: (2,4) 24 45 120 255, actual: " << c1 << endl;
    
    // test of member function: setCenter()
    Point center2(15, 16);
    c1.setCenter(center2);
    // test of member function: setRadius()
    int radius2 = -78;
    c1.setRadius(radius2);
    // test of member function: setColor()
    Color color2(78, 12, 45);
    c1.setColor(color2);
    
    // test of checkrange()
    Point center3(4, 6);
    int radius3 = -4;
    Color color3(24, 34, 56);
    
    Circle c2(center3, radius3, color3);
    cout << "Expected: (4,6) 4 24 34 56, actual: " << c2 << endl;

    // test of member functions getCenter(), getRadius() and getColor()
    cout << "Expected: (15,16) 78 78 12 45, actual: ";
    cout << c1.getCenter() << " "
         << c1.getRadius() << " "
         << c1.getColor() << endl;

    cout << endl;
    
    return;
}

void test_Rectangle() {
    cout << "-----Testing Rectangle-----" << endl;
    
    Point start(1, 0);
    Point end(20, 45);
    Color c1(255, 145, 220);
    Color c2(45, 255, 255);
    Color c3(90, 90, 90);
    Color c4(56, 190, 0);
    
    // test of first non-default constructor
    Rectangle r1(start, end, c1);
    cout << "Expected: (1,0) (20,45) 255 145 220, "
         << "actual: " << r1 << endl;
    
    // test of second non-default constructor
    Rectangle r2(start, end, c1, c2, c3, c4);
    cout << "Expected: (1,0) (20,45) 255 145 220 45 255 255 45 255 255 56 190 0, "
         << "actual: " << r2 << endl;
    
    Rectangle r3;
    Point start2(60, 60);
    Point end2(25, 10);
    Color c5(34, 111, 240);
    Color c6(124, 0, 78);
    Color c7(97, 134, 233);
    Color c8(38, 190, 255);
    
    // test of setter functions
    r3.setStart(start2);
    r3.setEnd(end2);
    r3.setColor(c5);

    // test of getter functions
    cout << "Expected: (60,60) (25,10) 34 111 240 124 0 78 38 190 255 97 134 233, actual: ";
    cout << r3.getStart() << " "
         << r3.getEnd() << " "
         << r3.getColorTopLeft() << " "
         << r3.getColorTopRight() << " "
         << r3.getColorBottomRight() << " "
         << r3.getColorBottomLeft() << endl;

    r3.setColorTopLeft(c5);
    r3.setColorTopRight(c6);
    r3.setColorBottomLeft(c7);
    r3.setColorBottomRight(c8);

    cout << "Expected: (60,60) (25,10) 34 111 240 124 0 78 38 190 255 97 134 233, actual: ";
    cout << r3.getStart() << " "
         << r3.getEnd() << " "
         << r3.getColorTopLeft() << " "
         << r3.getColorTopRight() << " "
         << r3.getColorBottomRight() << " "
         << r3.getColorBottomLeft() << endl;
    
    // test of member functions: read() and write()
    Rectangle r4;
    ifstream inFile;
    inFile.open("data2.txt");
    inFile >> r4;
    cout << "Expected: (5,48) (20,16) 98 24 66 98 24 66 98 24 66 98 24 66, actual: ";
    cout << r4 << endl;
    inFile >> r4;
    cout << "Expected: (65,12) (44,28) 234 255 203 102 234 50 1 9 20 54 68 90, actual: ";
    cout << r4 << endl;
    inFile.close();
    
    cout << endl;
    
    return;
}
