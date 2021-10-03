#ifndef __shape__
#define __shape__

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

struct shape {
    enum key {RECTANGLE, TRIANGLE, CIRCLE};

    enum color {RED, ORANGE, YELLOW, GREEN, BLUE, 
    INDIGO, VIOLET};

    key shape_key; 

    color shape_color;

    union {
        rectangle r;
        triangle t;
        circle c;
    };
};

// input data for shape
bool Input(shape &s, ifstream &ifdt);

// set color of shape
bool SetColor(shape &s, int &color_key);

// get random data for shape
bool InputRandom(shape &s);

// output data of shape
void Output(shape &s, ofstream &ofst);

// output color of shape
void OutColor(shape& s, ofstream &ofst);

// get perimeter of shape
double Perimeter(shape &s);

#endif
