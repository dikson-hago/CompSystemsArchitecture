#ifndef __triangle__
#define __triangle__

#include <fstream>
#include <cmath>

#include "rnd.h"
#include "shape.h"

class Triangle : public Shape {
private:
    int first_x_, first_y_;
    int second_x_, second_y_;
    int third_x_, third_y_;

    // get distanse between two coordinates of triangle
    double GetDistanseBetweenCoordinates(int x1, 
        int y1, int x2, int y2);

public:

    // constructor
    Triangle();

    // destructor
    ~Triangle();

    // input data for triangle
    void Input(ifstream &ifst) override;

    // get random data for triangle
    void InputRandom() override;

    // output data of triangle
    void Output(ofstream &ofst) override;

    // get perimeter of triangle
    double Perimeter() override;
};

#endif
