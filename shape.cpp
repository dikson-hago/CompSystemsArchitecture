#include "shape.h"

// input data for shape
bool Input(shape& s, ifstream &ifst) {
    int key, color_key;
    ifst >> key >> color_key;
    switch(key) {
        case 1:
            s.shape_key = shape::RECTANGLE;
            Input(s.r, ifst);
            return SetColor(s, color_key);
        case 2:
            s.shape_key = shape::TRIANGLE;
            Input(s.t, ifst);
            return SetColor(s, color_key);
        case 3:
            s.shape_key = shape::CIRCLE;
            Input(s.c, ifst);
            return SetColor(s, color_key);
        default:
            return false;
    }
}

// set color of shape
bool SetColor(shape &s, int &color_key) {
    switch(color_key) {
        case 1:
            s.shape_color = shape::RED;
            return true;
        case 2:
            s.shape_color = shape::ORANGE;
            return true;
        case 3:
            s.shape_color = shape::YELLOW;
            return true;
        case 4:
            s.shape_color = shape::GREEN;
            return true;
        case 5:
            s.shape_color = shape::BLUE;
            return true;
        case 6:
            s.shape_color = shape::INDIGO;
            return true;
        case 7:
            s.shape_color = shape::VIOLET;
            return true;
        default:
            return false;
    }

 }

// get random data for shape
bool InputRandom(shape& s) {
    auto shape_key = rand() % 3 + 1;
    auto color_key = rand() % 7 + 1;
    SetColor(s, color_key);
    switch(shape_key) {
        case 1:
            s.shape_key = shape::RECTANGLE;
            InputRandom(s.r);
            return true;
        case 2:
            s.shape_key = shape::TRIANGLE;
            InputRandom(s.t);
            return true;
        case 3:
            s.shape_key = shape::CIRCLE;
            InputRandom(s.c);
            return true;
        default:
            return false;
    }
}

// output data of shape
void Output(shape &s, ofstream &ofst) {
    switch(s.shape_key) {
        case shape::RECTANGLE:
            Output(s.r, ofst);
            break;
        case shape::TRIANGLE:
            Output(s.t, ofst);
            break;
        case shape::CIRCLE:
            Output(s.c, ofst);
            break;
        default:
            ofst << "Incorrect figure!" << endl;
    }
}

// output color of shape
void OutColor(shape& s, ofstream &ofst) {
    switch (s.shape_color)
    {
    case shape::RED:
        ofst << "RED";
        return;
    case shape::ORANGE:
        ofst << "ORANGE";
        return;
    case shape::YELLOW:
        ofst << "YELLOW";
        return;
    case shape::GREEN:
        ofst << "GREEN";
        return;
    case shape::BLUE:
        ofst << "BLUE";
        return;
    case shape::INDIGO:
        ofst << "INDIGO";
        return;
    case shape::VIOLET:
        ofst << "VIOLET";
        return;
    default:
        return;
    }
}

// get perimeter of shape
double Perimeter(shape &s) {
    switch(s.shape_key) {
        case shape::RECTANGLE:
            return Perimeter(s.r);
            break;
        case shape::TRIANGLE:
            return Perimeter(s.t);
            break;
        case shape::CIRCLE:
            return Perimeter(s.c);
            break;
        default:
            return 0.0;
    }
}
