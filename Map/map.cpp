#include "map.h"

void Map::initMaps() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _map_path[i][j] = Constants::SEA;
            _map_location[i][j] = Constants::SEA;
            _map_sectors[i][j] = Constants::SEA;
            _map_island[i][j] = Constants::SEA;
        }
    }
}

bool Map::validateFilling() {
    for(int i = 0; i < _rows; i++) {
        for(int j = 0; j < _columns; j++) {
            if(_map_path[i][j] != _map_sectors[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Map::isAvailableForSet(Coord coords) {
    if (coords.row < 0 || coords.column < 0 || coords.row >= _rows || coords.column >= _columns) {
        return false;
    }
    if (_map_island[coords.row][coords.column] == Constants::EMPRY_AREA) {
        return false;
    }
    return true;
}

Map::Map(int rows, int columns, int island_size, int sectors_amount) {
    _island_size = island_size;
    _sectors_amount = sectors_amount;
    _rows = rows;
    _columns = columns;
    std::cout << _rows << ' ' << _columns << std::endl;
    initMaps();
}

bool Map::setIsland(Coord coords) {
    _map_island[coords.row][coords.column] = Constants::EMPRY_AREA;
    _map_path[coords.row][coords.column] = Constants::EMPRY_AREA;
    _map_location[coords.row][coords.column] = Constants::EMPRY_AREA;
    _map_sectors[coords.row][coords.column] = Constants::EMPRY_AREA;
    return true;
}

void Map::setLocation(Coord location, char group_id) {
    if (_map_sectors[location.row][location.column] == group_id) {
        _map_path[location.row][location.column] = group_id;
    }
}

void Map::setSector(Coord coords, char sector_id) {
    _map_sectors[coords.row][coords.column] = sector_id;
}

int Map::getRows() { return _rows; }

int Map::getColumns() { return _columns; }

char Map::getSectorId(Coord coords) {
    return _map_sectors[coords.row][coords.column];
}

char Map::getAreaType(Coord coords) {
    return _map_island[coords.row][coords.column];
}

int Map::getIslandSize() { return _island_size; }

int Map::getSectorsAmount() { return _sectors_amount; }

bool Map::isFilled(int need_size) { return _island_size == need_size; }

void Map::showMap() {
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            std::cout << _map_sectors[i][j];
        }
        std::cout << "    ";
        for (int j = 0; j < _columns; j++) {
            std::cout << _map_island[i][j];
        }
        std::cout << '\n';
    }
}

void Map::showResultMap(char* file_name) {
    std::ofstream ofst(file_name);
    ofst << (this->validateFilling() ? "OK" : "Error") << '\n';
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            ofst << _map_sectors[i][j];
        }
        ofst << "    ";
        for (int j = 0; j < _columns; j++) {
            ofst << _map_path[i][j];
        }
        ofst << '\n';
    }
}

void Map::showLocation(Group* groups, int amount) {
    //system("cls");
    for (int i = 0; i < _rows; i++) {
        for (int j = 0; j < _columns; j++) {
            _map_location[i][j] = _map_island[i][j];
        }
    }
    for (int i = 0; i < amount; i++) {
        _map_location[groups[i].location.row][groups[i].location.column] = groups[i].id;
    }
    for (int i = 0; i < _rows; i++) {
        for(int j = 0; j < _columns; j++) {
            std :: cout << _map_sectors[i][j];
        }
        std::cout << "    ";
        for (int j = 0; j < _columns; j++) {
            std::cout << _map_path[i][j];
        }
        std::cout << "    ";
        for (int j = 0; j < _columns; j++) {
            std::cout << _map_location[i][j];
        }
        std::cout << '\n';
    }
    std :: cout << std :: endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(Constants::MAP_SLEEP));
}

Map::~Map() {}