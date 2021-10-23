#include "triangle.h"

// constructor
Triangle::Triangle() {
    first_x_ = 0;
    second_x_ = 0;
    third_x_ = 0;
    first_y_ = 0;
    second_y_ = 0;
    third_y_ = 0;
}

Triangle::~Triangle() {
    first_x_ = 0;
    second_x_ = 0;
    third_x_ = 0;
    first_y_ = 0;
    second_y_ = 0;
    third_y_ = 0;
}

// input data for triangle
void Triangle::Input(ifstream &ifst) {
    ifst >> first_x_ >> first_y_ >> second_x_ >> second_y_
    >> third_x_ >> third_y_;
}

// get random data for triangle
void Triangle::InputRandom() {
    first_x_ = Random();
    first_y_ = Random();
    second_x_ = Random();
    second_y_ = Random();
    third_x_ = Random();
    third_y_ = Random();
}

// output data of triangle
void Triangle::Output(ofstream &ofst) {
    ofst << " Triangle"
    << ": firstX = " << first_x_
    << ", firstY = " << first_y_
    << ", secondx = " << second_x_
    << ", secondY = " << second_y_
    << ", thirdX = " << third_x_
    << ", thirdY = " << third_y_
    << ". Perimeter = " << Perimeter() << "\n";
}

// get distanse between two coordinates of triangle
double Triangle::GetDistanseBetweenCoordinates(int x1, 
    int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// get perimeter of triangle
double Triangle::Perimeter() {
    return GetDistanseBetweenCoordinates(first_x_, first_y_, 
    second_x_, second_y_) +
    GetDistanseBetweenCoordinates(first_x_, first_y_, 
    third_x_, third_y_) +
    GetDistanseBetweenCoordinates(third_x_, third_y_, 
    second_x_, second_y_);
}
