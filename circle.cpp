#include "circle.h"

// input data for circle
void Input(circle &c, ifstream &ifst) {
    ifst >> c.center_x >> c.center_y >> c.radius;
}

// get random data for circle
void InputRandom(circle &c) {
    c.center_x = Random();
    c.center_y = Random();
    c.radius = Random();
}

// output circle data
void Output(circle &c, ofstream &ofst) {
    ofst << " Circle: center_x = " 
         << c.center_x << ", center_y = " << c.center_y
         << ", radius = " << c.radius
         << ". Perimeter = " << Perimeter(c) << "\n";
}

// get perimeter of circle
double Perimeter(circle &c) {
    double pi = 3.14159265359;
    return 2 * pi * c.radius;
}
