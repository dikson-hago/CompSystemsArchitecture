#include "rectangle.h"

//constructor
Rectangle::Rectangle() {
    high_left_x_ = 0;
    high_left_y_ = 0;
    low_right_x_ = 0;
    low_right_y_ = 0;
}

// destructor
Rectangle::~Rectangle() {
    high_left_x_ = 0;
    high_left_y_ = 0;
    low_right_x_ = 0;
    low_right_y_ = 0;
}

// input data for rectangle
void Rectangle::Input(ifstream &ifst) {
    ifst >> high_left_x_ >> high_left_y_ >> low_right_x_
    >> low_right_y_;
    is_valid_ = ValidateRectangle();
}

// check input data
bool Rectangle::ValidateRectangle() {
    if(high_left_x_ < low_right_x_ && high_left_y_ > low_right_y_) {
        return true;
    }
    return false;
}

// get random data for rectangle
void Rectangle::InputRandom() {
    high_left_x_ = Random();
    high_left_y_ = Random();
    low_right_x_ = Random();
    low_right_y_ = Random();
    is_valid_ = ValidateRectangle();
}

// output data of rectangle
void Rectangle::Output(ofstream &ofst) {
    ofst << " Rectangle: highLeftX = " << high_left_x_ 
    << ", highLeftY = " << high_left_y_
    << ", lowRightX = " << low_right_x_
    << ", lowRightY = " << low_right_y_
    << ". Perimeter = " << Perimeter() << "\n";
    if(is_valid_ == false) {
        ofst << "Earlier Rectangle was not valid \n";
    }
}

// get perimeter of rectangle
double Rectangle::Perimeter() {
    return 2 * (std::abs(low_right_x_ - high_left_x_) +
    std::abs(high_left_y_ - low_right_y_));
}
