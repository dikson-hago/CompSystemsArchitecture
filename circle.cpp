#include "circle.h"

// constructor
Circle::Circle() {
    center_x_ = 0;
    center_y_ = 0;
    radius_ = 0;
}

// destructor
Circle::~Circle() {
    center_x_ = 0;
    center_y_ = 0;
    radius_ = 0;
}

// input data for circle
void Circle::Input(ifstream &ifst) {
    ifst >> center_x_ >> center_y_ >> radius_;
}

// get random data for circle
void Circle::InputRandom() {
    center_x_ = Random();
    center_y_ = Random();
    radius_ = Random();
}

// output circle data
void Circle::Output(ofstream &ofst) {
    ofst << " Circle: center_x = " 
         << center_x_ << ", center_y = " << center_y_
         << ", radius = " << radius_
         << ". Perimeter = " << Perimeter() << "\n";
}

// get perimeter of circle
double Circle::Perimeter() {
    double pi = 3.14159265359;
    return 2 * pi * radius_;
}
