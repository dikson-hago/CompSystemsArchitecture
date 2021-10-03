#include "rectangle.h"

// input data for rectangle
void Input(rectangle &r, ifstream &ifst) {
    ifst >> r.highLeftX >> r.highLeftY >> r.lowRightX 
    >> r.lowRightY;
    r.isValid = ValidateRectangle(r);
}

// check input data
bool ValidateRectangle(rectangle &r) {
    if(r.highLeftX < r.lowRightX && r.highLeftY > r.lowRightY) {
        return true;
    }
    return false;
}

// get random data for rectangle
void InputRandom(rectangle &r) {
    r.highLeftX = Random();
    r.highLeftY = Random();
    r.lowRightX = Random();
    r.lowRightY = Random();
}

// output data of rectangle
void Output(rectangle &r, ofstream &ofst) {
    ofst << " Rectangle: highLeftX = " << r.highLeftX 
    << ", highLeftY = " << r.highLeftY
    << ", lowRightX = " << r.lowRightX
    << ", lowRightY = " << r.lowRightY
    << ". Perimeter = " << Perimeter(r) << "\n";
    if(r.isValid == false) {
        ofst << "Earlier rectangle was not valid \n";
    }
}

// get perimeter of rectangle
double Perimeter(rectangle &r) {
    return 2 * (std::abs(r.lowRightX - r.highLeftX) +
    std::abs(r.highLeftY - r.lowRightY));
}
