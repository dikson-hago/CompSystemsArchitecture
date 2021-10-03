#ifndef __circle__
#define __circle__

#include <fstream>
#include "rnd.h"

using namespace std;

struct circle {
    int center_x, center_y;
    double radius;
};

// input data for circle
void Input(circle &c, ifstream &ifst);

// get random data for circle
void InputRandom(circle &e);

// output data of circle
void Output(circle &t, ofstream &ofst);

// get perimeter of circle
double Perimeter(circle &t);

#endif
