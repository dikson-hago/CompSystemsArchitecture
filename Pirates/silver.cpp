#include "silver.h"

Coord Silver::_location(0, 0);
int Silver::_groups_amount = 0;
Map* Silver::_map = nullptr;
std::mutex Silver::locker;
int Silver::_counter_finished_groups = 0;
Group Silver::groups[Constants::MAX_GROUP_SIZE];
std::thread Silver::threads[Constants::MAX_GROUP_SIZE];

void Silver::setData(Coord location, int groups_amount, Map* map) {
    _map = map;
    _location = location;
    _groups_amount = groups_amount;
    char group_id = '1';
    for (int i = 0; i < groups_amount; i++, group_id++) {
        groups[i] = Group(group_id, _location);
    }
}

void Silver::setGroup(int group_id) {
    _map->setLocation(groups[group_id].location, groups[group_id].id);
    _map->showLocation(groups, _groups_amount);
}

void Silver::runGroup(int group_id, int deep) {
    locker.lock();
    setGroup(group_id);
    locker.unlock();
    Coord old_location = groups[group_id].location;
    for (int i = 1; i < Steps::size; i++) {
        locker.lock();
        Coord new_location = old_location + Steps::coords[i];
        bool can_run = _map->getAreaType(new_location) != Constants::SEA;
        can_run = can_run && groups[group_id].isValidLocation(new_location, _map->getRows(), _map->getColumns());
        locker.unlock();
        if (can_run) {
            groups[group_id].setLocation(new_location);
            runGroup(group_id, deep + 1);
            groups[group_id].setLocation(old_location);
            locker.lock();
            setGroup(group_id);
            locker.unlock();
        }
    }
    if (deep == 1) {
        _counter_finished_groups++;
    }
}

void Silver::runGroups() {
    for (int i = 0; i < _groups_amount; i++) {
        threads[i] = std::thread(&Silver::runGroup, i, 1);
    }
    for (int i = 0; i < _groups_amount; i++) {
        threads[i].join();
    }
    while (true) {
        locker.lock();
        if (_counter_finished_groups == _groups_amount) {
            locker.unlock();
            return;
        }
        locker.unlock();
    }
}

