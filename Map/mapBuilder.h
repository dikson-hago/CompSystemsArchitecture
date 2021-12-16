#include "map.h"
#include "../Models/randomiser.h"
#include <mutex>
#include <thread>
#include <iostream>
#include <fstream>

class MapBuilder {
private:
    static int _sector_size;
    static std::mutex locker;
    static int _counter_init_sectors;
    static Map* _map;

    static void initMap(Coord coords, int thread_id);

    static void runMapInitialisation(Coord location);

    static void runMapFilling();

public:
    static void createMap(Map* map, Coord start_location);
};