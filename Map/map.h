#ifndef __map__
#define __map__

#include <iostream>
#include<fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include "../Models/steps.h"
#include "../Models/constants.h"
#include "../Pirates/group.h"

class Map {
private:
    char _map_island[Constants::MAX_MAP_SIZE][Constants::MAX_MAP_SIZE];
    char _map_path[Constants::MAX_MAP_SIZE][Constants::MAX_MAP_SIZE];
    char _map_location[Constants::MAX_MAP_SIZE][Constants::MAX_MAP_SIZE];
    char _map_sectors[Constants::MAX_MAP_SIZE][Constants::MAX_MAP_SIZE];
    int _island_size;
    int _sectors_amount;
    int _rows, _columns;

    void initMaps();

public:
    bool isAvailableForSet(Coord coords);

    Map(int rows, int columns, int island_size, int sectors_amount);

    bool setIsland(Coord coords);

    void setLocation(Coord location, char group_id);

    void setSector(Coord coords, char group_id);

    int getRows();

    int getColumns();

    char getSectorId(Coord coords);

    char getAreaType(Coord coords);

    int getIslandSize();

    int getSectorsAmount();

    bool isFilled(int need_size);

    void showMap();

    void showResultMap(char* file_name);

    void showLocation(Group* groups, int amount);

    bool validateFilling();

    ~Map();
};

#endif