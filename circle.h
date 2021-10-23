#ifndef __circle__
#define __circle__

#include <fstream>

#include "rnd.h"
#include "shape.h"

class Circle : public Shape {
private:
    int center_x_, center_y_;
    double radius_;
public:
    // constructor
    Circle();

    // destructor
    ~Circle();

    // input data for circle
    void Input(ifstream &ifst) override;

    // get random data for circle
    void InputRandom() override;

    // output data of circle
    void Output(ofstream &ofst) override;

    // get perimeter of circle
    double Perimeter() override;
};



#endif
