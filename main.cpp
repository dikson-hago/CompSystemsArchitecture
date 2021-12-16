// // input example with file
// // ./bin/task01 -f tests/test01.txt tests/out.txt
// // input example with number of random
// // ./bin/task01 -n 100 tests/out.txt

#include <iostream>
#include <fstream>
#include "Map/map.h"
#include "Map/mapBuilder.h"
#include "Pirates/silver.h"
#include "errorMessages.h"

int main(int argc, char* argv[]) {
    if(argc != 3) {
        ErrorMessages::IncorrectAmountOfArgs();
        return -1;
    }
    int rows, columns, island_size, sectors_amount, groups_amount;
    char* input_file_name;
    char* output_file_name;
    Coord start_location(0, 0);
    Map* map = nullptr;
    try {
        input_file_name = argv[1];
        output_file_name = argv[2];
        std::ifstream ifst(input_file_name);
        ifst >> rows >> columns >> island_size >> sectors_amount;
        if(rows * columns < island_size || sectors_amount > rows * columns) {
            throw -1;
        }
        groups_amount = sectors_amount;
        Map* map = new Map(rows, columns, island_size, sectors_amount);
        MapBuilder::createMap(map, start_location);
        //map->showMap();
        Silver::setData(start_location, groups_amount, map);
        Silver::runGroups();
        map->showResultMap(output_file_name);
        delete map;
        
    } catch (...) {
        ErrorMessages::IncorrectInputData();
        return -1;
    }
    
    return 0;
}

