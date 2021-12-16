#include "randomiser.h"

int Randomiser::getRandom(int from, int to) {
    srand(time(NULL));
    return from + rand() % (to - from + 1);
}