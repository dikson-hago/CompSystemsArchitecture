#ifndef __coord__
#define __coord__

#include "randomiser.h"

struct Coord {
    int row;
    int column;

    static Coord getRandomCoord(int from, int to);

    Coord();

    Coord operator + (Coord coord) {
        return Coord(this->row + coord.row, this->column + coord.column);
    }

    Coord(int new_row, int new_column);

    bool isValidCoord(int rows, int columns);
};

#endif
