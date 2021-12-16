#ifndef __captain__
#define __captain__

#include "group.h"
#include "../Map/map.h"
#include <thread>
#include <mutex>

class Silver {
private:
    static Coord _location;
    static Group groups[Constants::MAX_GROUP_SIZE];
    static std::thread threads[Constants::MAX_GROUP_SIZE];
    static int _counter_finished_groups;
    static int _groups_amount;
    static Map* _map;
    static std::mutex locker;

    static void setGroup(int group_id);

    static void runGroup(int group_id, int deep);
public:
    static void setData(Coord location, int groups_amount, Map* map);

    static void runGroups();
};

#endif