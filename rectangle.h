#ifndef __rectangle__
#define __rectangle__

#include <fstream>
#include "rnd.h"

using namespace std;

struct rectangle {
    int highLeftX, highLeftY;
    int lowRightX, lowRightY;
    bool isValid;
};

// input data for rectangle
void Input(rectangle &r, ifstream &ifst);

// check input data
bool ValidateRectangle(rectangle &r);

// get random data for rectangle
void InputRandom(rectangle &r);

// output data of rectangle
void Output(rectangle &r, ofstream &ofst);

// get perimeter of rectangle
double Perimeter(rectangle &r);

#endif
