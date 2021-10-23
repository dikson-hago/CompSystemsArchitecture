#ifndef __rectangle__
#define __rectangle__

#include <fstream>

#include "rnd.h"
#include "shape.h"

class Rectangle : public Shape {
private:
    int high_left_x_, high_left_y_;
    int low_right_x_, low_right_y_;
    bool is_valid_;

    // check input data
    bool ValidateRectangle();

public:
    Rectangle();

    ~Rectangle();

    // input data for rectangle
    void Input(ifstream &ifst) override;

    // get random data for rectangle
    void InputRandom() override;

    // output data of rectangle
    void Output(ofstream &ofst) override;

    // get perimeter of rectangle
    double Perimeter();
};
#endif
