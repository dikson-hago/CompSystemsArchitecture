#include "coord.h"

Coord::Coord() {
    row = 0;
    column = 0;
}

Coord Coord::getRandomCoord(int from, int to) {
    return Coord(Randomiser::getRandom(from, to + 1), Randomiser::getRandom(from, to + 1));
}

Coord::Coord(int new_row, int new_column) {
    row = new_row;
    column = new_column;
}

bool Coord::isValidCoord(int rows, int columns) {
    return (row >= 0) && (column >= 0) && (row < rows) && (column < columns);
}

