#include "mapBuilder.h"

Map* MapBuilder::_map = nullptr;
int MapBuilder::_sector_size = 0;
int MapBuilder::_counter_init_sectors = 0;
std::mutex MapBuilder::locker;

void MapBuilder::initMap(Coord coords, int thread_id) {
    locker.lock();
    if (!_map->isFilled(_counter_init_sectors) && _map->isAvailableForSet(coords)) {
        _map->setIsland(coords);
        _counter_init_sectors++;
    }
    else {
        locker.unlock();
        return;
    }
    locker.unlock();
    int random_id = Randomiser::getRandom(0, Steps::size + 1);
    for (int i = 0; i < Steps::size * 2; i++, random_id = (random_id + 1) % Steps::size) {
        initMap(coords + Steps::coords[random_id], thread_id);
    }
}

void MapBuilder::runMapInitialisation(Coord location) {
    for (int i = 0; i < Steps::size; i++) {
        Coord new_location(location.row + Steps::coords[i].row,
            location.column + Steps::coords[i].column);
        std::thread th(&MapBuilder::initMap, new_location, i);
        th.join();
    }
    while (true)
    {
        locker.lock();
        if (_map->isFilled(_counter_init_sectors)) {
            locker.unlock();
            return;
        }
        locker.unlock();
    }
}

void MapBuilder::runMapFilling() {
    char sector_id = '1';
    int sectors_counter = 0;
    int counter_squares_in_sector = 0;
    for (int j = 0; j < _map->getColumns(); j++) {
        for (int i = 0; i < _map->getRows(); i++) {
            Coord new_coords(i, j);
            if (_map->getAreaType(new_coords) == Constants::EMPRY_AREA) {
                counter_squares_in_sector++;
                _map->setSector(new_coords, sector_id);
            }
            if (counter_squares_in_sector == _sector_size) {
                counter_squares_in_sector = 0;
                if (sectors_counter + 1 < _map->getSectorsAmount()) {
                    sectors_counter++;
                    sector_id++;
                }
            }
        }
    }
}

void MapBuilder::createMap(Map* map, Coord start_location) {
    _map = map;
    _sector_size = _map->getIslandSize() / _map->getSectorsAmount();
    _counter_init_sectors = 0;
    runMapInitialisation(start_location);
    runMapFilling();
}
