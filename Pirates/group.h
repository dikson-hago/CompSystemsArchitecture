#ifndef __group__
#define __group__

#include "../Models/constants.h"
#include "../Models/steps.h"

struct Group {
private:
    void initMap();
public:
    Coord location;
    bool used[Constants::MAX_MAP_SIZE][Constants::MAX_MAP_SIZE];
    char id;
    Group();

    Group(char new_id, Coord new_location);

    void setLocation(Coord new_location);

    bool isValidLocation(Coord coord, int rows, int columns);
};

#endif