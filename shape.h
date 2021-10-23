#ifndef __shape__
#define __shape__

#include <fstream>
#include <iostream>

using namespace std;

#include "enums.h"

class Shape {
private:
    ShapeName shape_name_; 
    ColorName shape_color_;

public:

    // input data for shape
    virtual void Input(ifstream &ifst) {};

    // get random data for shape
    virtual void InputRandom() {};

    // output data of shape
    virtual void Output(ofstream &ofst) {};

    // get perimeter of shape
    virtual double Perimeter() { return 0; };

    // set color of shape
    bool SetColor(int &color_key);

    // output color of shape
    void OutColor(ofstream &ofst);
};
#endif
