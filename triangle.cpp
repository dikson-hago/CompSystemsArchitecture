#include "triangle.h"
#include <cmath>

// input data for triangle
void Input(triangle &t, ifstream &ifst) {
    ifst >> t.first_x >> t.first_y >> t.second_x >> t.second_y
    >> t.third_x >> t.third_y;
}

// get random data for triangle
void InputRandom(triangle &t) {
    t.first_x = Random();
    t.first_y = Random();
    t.second_x= Random();
    t.second_y= Random();
    t.third_x = Random();
    t.third_y = Random();
}

// output data of triangle
void Output(triangle &t, ofstream &ofst) {
    ofst << " Triangle"
    << ": firstX = " << t.first_x
    << ", firstY = " << t.first_y
    << ", secondx = " << t.second_x
    << ", secondY = " << t.second_y
    << ", thirdX = " << t.third_x
    << ", thirdY = " << t.third_y
    << ". Perimeter = " << Perimeter(t) << "\n";
}

// get distanse between two coordinates of triangle
double GetDistanseBetweenCoordinates(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// get perimeter of triangle
double Perimeter(triangle &t) {
    return GetDistanseBetweenCoordinates(t.first_x, t.first_y, 
    t.second_x, t.second_y) +
    GetDistanseBetweenCoordinates(t.first_x, t.first_y, 
    t.third_x, t.third_y) +
    GetDistanseBetweenCoordinates(t.third_x, t.third_y, 
    t.second_x, t.second_y);
}
