#include "group.h"

void Group::initMap() {
    for (int i = 0; i < Constants::MAX_MAP_SIZE; i++) {
        for (int j = 0; j < Constants::MAX_MAP_SIZE; j++) {
            used[i][j] = false;
        }
    }
}

Group::Group() {
    location = Coord(0, 0);
    id = '0';
    initMap();
}

Group::Group(char new_id, Coord new_location) {
    location = new_location;
    id = new_id;
    initMap();
}

void Group::setLocation(Coord new_location) {
    location = new_location;
    used[location.row][location.column] = true;
}

bool Group::isValidLocation(Coord coord, int rows, int columns) {
    return coord.isValidCoord(rows, columns) && !used[coord.row][coord.column];
}