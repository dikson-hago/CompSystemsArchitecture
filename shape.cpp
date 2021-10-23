#include "shape.h"

// set color of shape
bool Shape::SetColor(int &color_key) {
    switch(color_key) {
        case 1:
            shape_color_ = ColorName::RED;
            return true;
        case 2:
            shape_color_ = ColorName::ORANGE;
            return true;
        case 3:
            shape_color_ = ColorName::YELLOW;
            return true;
        case 4:
            shape_color_ = ColorName::GREEN;
            return true;
        case 5:
            shape_color_ = ColorName::BLUE;
            return true;
        case 6:
            shape_color_ = ColorName::INDIGO;
            return true;
        case 7:
            shape_color_ = ColorName::VIOLET;
            return true;
        default:
            return false;
    }

 }

// output color of shape
void Shape::OutColor(ofstream &ofst) {
    switch (shape_color_)
    {
    case ColorName::RED:
        ofst << "RED";
        return;
    case ColorName::ORANGE:
        ofst << "ORANGE";
        return;
    case ColorName::YELLOW:
        ofst << "YELLOW";
        return;
    case ColorName::GREEN:
        ofst << "GREEN";
        return;
    case ColorName::BLUE:
        ofst << "BLUE";
        return;
    case ColorName::INDIGO:
        ofst << "INDIGO";
        return;
    case ColorName::VIOLET:
        ofst << "VIOLET";
        return;
    default:
        return;
    }
}