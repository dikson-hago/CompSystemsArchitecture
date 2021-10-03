#ifndef __triangle__
#define __triangle__

#include <fstream>
#include <iostream>

using namespace std;

# include "rnd.h"

struct triangle {
    int first_x, first_y;
    int second_x, second_y;
    int third_x, third_y;
};

// input data for triangle
void Input(triangle &t, ifstream &ifst);

// get random data for triangle
void InputRandom(triangle &e);

// output data of triangle
void Output(triangle &t, ofstream &ofst);

// get perimeter of triangle
double Perimeter(triangle &t);

#endif 
